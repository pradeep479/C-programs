String save_data;
uint8_t count = 0;
int num;
int range_1 = 10;
int range_2 = 20;
	count++;
while(file.available()){
	save_data = readStringUntil(\n);
	if(count == 10){
		Serial.println(save_data);
	}
	//for (num = 10; num <= 20; num++) {
}