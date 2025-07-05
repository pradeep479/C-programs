/******************************************************************************
 *  Original user code – NO functional changes, comments only
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>

/* ---------------------------------------------------------------------------
 * Example frames exactly as they come from the IC (little-endian on the bus)
 * Each 64-bit word contains:
 *   head • id • tempH • tempL • humH • humL • checksum • tail
 * --------------------------------------------------------------------------*/
const uint64_t frames[] = {
    0xFE42340C8F02F7FF,  /* valid  │ ID=0x42 │ T=31.24 °C │ RH=65.5 % */
    0xFE17C409E80331FF,  /* valid  │ ID=0x17 │ T=25.00 °C │ RH=100.0 % */
    0xAA55B80B710295FF,  /* invalid head    (0xAA ≠ 0xFE)              */
    0xFE33AC0D5802C9FF   /* invalid checksum                           */
};

/* ---------------------------------------------------------------------------
 * Union that lets us see the same 64-bit value either as one integer (raw)
 * or broken into bytes/half-words.
 * The struct layout matches the **little-endian** byte order of the incoming
 * data (tail at offset 0, head at offset 7).
 * --------------------------------------------------------------------------*/
typedef union
{
    uint64_t raw;
    struct __attribute__((packed))      /* keep exact byte order               */
    {
        uint8_t tail;                   /* 0xFF                                */
        uint8_t cksm;                   /* XOR checksum                        */
        uint16_t humd;                  /* raw humidity (unsigned, little-end) */
        int16_t  temp;                  /* raw temperature (signed, little-end)*/
        uint8_t id;                     /* sensor / packet ID                  */
        uint8_t head;                   /* 0xFE                                */
    } bytes;
} frame_t;

/* ---------------------------------------------------------------------------
 * Simple container to hold the decoded values of all valid frames.
 * The size (4) matches the example stream, but could be made dynamic.
 * --------------------------------------------------------------------------*/
typedef struct
{
    float temperature[4];
    float humidity[4];
    int   Id[4];
} dataArray;

/* ---------------------------------------------------------------------------
 * Globals that keep bookkeeping.  (They default to 0 because they are global.)
 * --------------------------------------------------------------------------*/
int   validCnt   = 0;
int   inValidCnt = 0;
float avgTemp    = 0.0f;
float avgHumd    = 0.0f;

/* ---------------------------------------------------------------------------
 * getDecodedFrame()
 * Simply copies the 64-bit word into a union so the fields can be accessed.
 * No byte-swapping is required because the struct is already little-endian.
 * --------------------------------------------------------------------------*/
frame_t getDecodedFrame(uint64_t x)
{
    frame_t decoded;
    decoded.raw = x;
    return decoded;
}

/* ---------------------------------------------------------------------------
 * extractData()
 * Verifies head/tail, recomputes the XOR checksum, converts raw values into
 * physical units, and stores them in the output array.
 * RETURNS:
 *   0 → frame valid
 *   1 → head/tail error
 *   2 → checksum error
 * --------------------------------------------------------------------------*/
int extractData(const frame_t* fm, dataArray* d)
{
    /* ----- recompute checksum (XOR of ID, TempH, TempL, HumH, HumL) ------- */
    uint8_t checksum = fm->bytes.id
                       ^ ((fm->bytes.temp  >> 8) & 0xFF)
                       ^ ((fm->bytes.temp       ) & 0xFF)
                       ^ ((fm->bytes.humd  >> 8) & 0xFF)
                       ^ ((fm->bytes.humd       ) & 0xFF);

    /* --------------------------- validate frame --------------------------- */
    if (fm->bytes.head == 0xFE && fm->bytes.tail == 0xFF)
    {
        if (checksum == fm->bytes.cksm)
        {
            /* ------- byte-swap raw values to big-endian for calculations --- */
            int16_t  t = ((fm->bytes.temp  & 0xFF) << 8) |
                         ((fm->bytes.temp  >> 8) & 0xFF);
            uint16_t h = ((fm->bytes.humd  & 0xFF) << 8) |
                         ((fm->bytes.humd  >> 8) & 0xFF);

            /* ------------- store converted results in the output array ----- */
            d->temperature[validCnt] = t / 100.0f;   /* °C                    */
            d->humidity   [validCnt] = h / 10.0f;    /* %RH                   */
            d->Id         [validCnt] = fm->bytes.id; /* store ID              */
            validCnt++;                              /* increment on success  */
            return 0;                                /* 0 = frame is valid    */
        }
        else
        {
            inValidCnt++;    /* bad checksum */
            return 2;
        }
    }
    else
    {
        inValidCnt++;        /* bad head/tail */
        return 1;
    }
}

/* ---------------------------------------------------------------------------
 * main()
 * Loops over all frames, prints a table of valid ones, tracks statistics,
 * and finally prints the average T & RH along with the invalid-frame count.
 * --------------------------------------------------------------------------*/
int main(void)
{
    frame_t   f;
    dataArray finalData;     /* will hold decoded results */

    puts(" Idx    ID  Temp(°C)  Hum(%RH)");
    puts(" ---    --  --------  --------");

    for (int i = 0; i < 4; ++i)
    {
        f = getDecodedFrame(frames[i]);       /* interpret current 64-bit word */

        if (extractData(&f, &finalData) == 0) /* only print if frame is valid  */
        {
            /* NOTE: uses loop index ‘i’ for table row, while data are stored
             *       at index ‘validCnt-1’.  This works *here* because the
             *       first two frames are valid, but would mis-align rows if
             *       later frames were valid again.  See “Type 2” for a fix. */
            printf(" %d      %d  %6.2f     %5.1f\n",
                   validCnt, finalData.Id[i],
                   finalData.temperature[i], finalData.humidity[i]);
        }
    }

    printf("Invalid Frames: %d\n", inValidCnt);

    /* --------------------- compute simple arithmetic mean ---------------- */
    for (int j = 0; j < validCnt; ++j)
    {
        avgTemp += finalData.temperature[j];
        avgHumd += finalData.humidity[j];
    }
    printf("Average T: %.2f °C\nAverage RH: %.2f %%\n",
           avgTemp / validCnt, avgHumd / validCnt);

    return 0;
}


//======================================== CHATGPT STD CODE =============================================

/******************************************************************************
 *  Refactored solution – compact, standard C11, explanatory comments
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>

/* ---------------------------------------------------------------------------
 * 1. Raw 64-bit frames (little-endian on the bus)
 * --------------------------------------------------------------------------*/
static const uint64_t frames[] = {
    0xFE42340C8F02F7FF,
    0xFE17C409E80331FF,
    0xAA55B80B710295FF,
    0xFE33AC0D5802C9FF
};
#define FRAME_CNT  (sizeof(frames) / sizeof(frames[0]))

/* ---------------------------------------------------------------------------
 * 2. On-host representation of a decoded frame
 * --------------------------------------------------------------------------*/
typedef struct {
    uint8_t id;
    float   temp_c;    /* °C  */
    float   rh_pct;    /* %RH */
} sensor_data_t;

/* ---------------------------------------------------------------------------
 * 3. Byte-swap helpers (use compiler builtin if available)
 * --------------------------------------------------------------------------*/
#if defined(__clang__) || defined(__GNUC__)
#define BSWAP64(v)  __builtin_bswap64(v)
#else
static uint64_t BSWAP64(uint64_t v)
{
    return ((v & 0x00000000000000FFull) << 56) |
           ((v & 0x000000000000FF00ull) << 40) |
           ((v & 0x0000000000FF0000ull) << 24) |
           ((v & 0x00000000FF000000ull) <<  8) |
           ((v & 0x000000FF00000000ull) >>  8) |
           ((v & 0x0000FF0000000000ull) >> 24) |
           ((v & 0x00FF000000000000ull) >> 40) |
           ((v & 0xFF00000000000000ull) >> 56);
}
#endif

/* ---------------------------------------------------------------------------
 * 4. Parse & validate a single 64-bit frame
 *    RETURNS 0 on success, non-zero on failure.
 * --------------------------------------------------------------------------*/
static int parse_frame(uint64_t raw, sensor_data_t *out)
{
    /* Swap to big-endian so byte 0 == head, byte 7 == tail */
    raw = BSWAP64(raw);

    uint8_t head = (raw >> 56) & 0xFF;
    uint8_t id   = (raw >> 48) & 0xFF;
    uint16_t tbe = (raw >> 32) & 0xFFFF;   /* temp big-endian */
    uint16_t hbe = (raw >> 16) & 0xFFFF;   /* hum  big-endian */
    uint8_t  cks = (raw >>  8) & 0xFF;
    uint8_t  tail=  raw        & 0xFF;

    /* Head / tail check */
    if (head != 0xFE || tail != 0xFF) return 1;

    /* Checksum (XOR of id + all four data bytes) */
    uint8_t calc =
        id ^ (tbe >> 8) ^ (tbe & 0xFF) ^ (hbe >> 8) ^ (hbe & 0xFF);
    if (calc != cks) return 2;

    /* Convert to physical units */
    int16_t t_raw = (int16_t)tbe;      /* signed */
    uint16_t h_raw= hbe;              /* unsigned */

    out->id      = id;
    out->temp_c  = t_raw / 100.0f;
    out->rh_pct  = h_raw / 10.0f;
    return 0;
}

/* ---------------------------------------------------------------------------
 * 5. Main demo
 * --------------------------------------------------------------------------*/
int main(void)
{
    sensor_data_t results[FRAME_CNT];
    size_t        valid = 0, invalid = 0;
    float         acc_t = 0.0f, acc_h = 0.0f;

    for (size_t i = 0; i < FRAME_CNT; ++i) {
        if (parse_frame(frames[i], &results[valid]) == 0) {
            acc_t += results[valid].temp_c;
            acc_h += results[valid].rh_pct;
            ++valid;
        } else {
            ++invalid;
        }
    }

    /* ---------- pretty print table ---------- */
    puts("Idx  ID   Temp(°C)  Hum(%RH)");
    puts("---  --   --------  --------");

    for (size_t i = 0; i < valid; ++i) {
        printf("%3zu  %02X   %8.2f  %8.1f\n",
               i, results[i].id,
               results[i].temp_c, results[i].rh_pct);
    }

    printf("Invalid frames: %zu\n", invalid);

    if (valid) {
        printf("Average T:  %.2f °C\n", acc_t / valid);
        printf("Average RH: %.2f %%\n", acc_h / valid);
    }

    return 0;
}
