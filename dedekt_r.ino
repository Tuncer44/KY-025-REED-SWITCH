//Tuncer Yılmaz--Arduino UNO ile-KY-025 REED SWITCH Manyetik Dedektör

#include <LiquidCrystal.h> //LCD kütüphanesini kodumuza dahil ediyoruz

int sinyalpin = A0; //Bağladığımız pinlere göre tanımlamalarımızı yapıyoruz
int buzzer = 11; //Buzzerın +sı 11.pine
int degisken;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //LCD pinlerini tanımlıyoruz


void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT); //buzzer pinini INPUT olarak tanımlıyoruz

  digitalWrite(sinyalpin,INPUT); //a0  pini OUTPUT olarak tanımlıyoruz
  
  beep(50);
  beep(50);
  beep(50);
  delay(500);

}

void loop() {
 

  Serial.print("  ");
  
  lcd.print("  ");
  
  
  lcd.setCursor(0, 0);
  delay(1000); //1000 milisaniye bekle
  // değerleri 1 saniye boyunca ekranda göreceğiz
  
  
  lcd.clear(); //Ekranı temizle
  delay(150); //150 milisaniye bekle
  //----------------------------------------------------------------------
  degisken = digitalRead(sinyalpin);

  if (degisken==HIGH) //
  {
    Serial.println("DEGER = YOK ");
    lcd.setCursor(0, 0);   //İmleci 1. sütuna al .birinci değer sütun
    lcd.print("DURUM");
    lcd.setCursor(0, 1);   //İmleci 1. sütuna al .birinci değer sütun
    lcd.print("ManyetikAlanYok");
    delay(1000);
  } 
  else {
    beep(50);
    beep(50);
    beep(50);
    Serial.println("Manyetik Alan Tespit Edildi"); //Belirlediğimiz kıstaslara uymayan diğer değerler
    lcd.setCursor(0, 0);   //İmleci 1. sütun 1.satıra al .birinci değer sütun ikinci değer satır
    lcd.print("DURUM");
    lcd.setCursor(0, 1); //İmleci 2. satır 1. sütuna al
    lcd.print("ManyetikAlanVAR");
    delay(1000);
  }

  Serial.println(); //Serial monitörde bir satır aşağı geç
  delay(1000); //1000 milisaniye bekle
  lcd.clear(); //LCD ekranı temizle
  delay(1000);

}
  void beep(unsigned char delayms){
  digitalWrite(buzzer,HIGH);
  delay(delayms);
  digitalWrite(buzzer, LOW);
  delay(delayms);
}
