#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String agAdi = "***";      //kablosuz ag ad
String agSifresi = "****";  //kablosuz ag sifre

String ip = "184.106.153.149";  //thingspeak sitesinin ip adresi

#define DEBUG true
//farkli api'lari kullanmak icin butonlar
int data;

SoftwareSerial esp(11, 12);  //tx,rx pinleri

void setup() {
  lcd.begin();

  Serial.begin(9600);  //Seri port haberlesme
  esp.begin(115200);   //esp haberlesmesi
  //esp.begin(9600);
  //esp.println("AT+UART_DEF=9600,8,1,0,0"); //bu satir esp modulu 115200 ise 1 defa calistirilir ve 9600 yapilmis olur

  esp.println("AT");
  Serial.println("AT Yollandi");
  while (!esp.find("OK"))  //modul hazir olana kadar beklenir
  {
    esp.println("AT");
    Serial.println("ESP8266 Bulunamadi");
  }
  Serial.println("OK komutu alindi");

  esp.println("AT+CWMODE=1");  //esp8266 komutu client olarak ayarlanir yani internetten veri alacak.

  while (!esp.find("OK"))  //ayar yapilana kadar beklenir
  {
    esp.println("AT+CWMODE=1");
    Serial.println("Modul Ayari yapiliyor");
  }
  Serial.println("Modul client olarak ayarlandi");
  Serial.println("Aga Baglaniliyor... ");
  esp.println("AT+CWJAP=\"" + agAdi + "\",\"" + agSifresi + "\"");  //kablosuz aga baglanir
  while (!esp.find("OK"))
    ;  //aga baglanana kadar beklenir
  Serial.println("Ağa Baglandi.");
  delay(1000);

  lcd.clear();
  lcd.home();  //cursor basa alniri
}

void loop() {
  esp.println("AT+CIPSTART=\"TCP\",\"" + ip + "\",80");  //Thingspeak sitesine TCP portokoluyle baglanilir
  if (esp.find("Error"))                                 //hata kontrolu yapilir
  {
    Serial.println("AT+CIPSTART Error");
  }
  // Serial.println(sterlin());
  // Serial.println(euro());
  //Button'a gore euro veya sterlin verisini gosteren if komutu yap

  /*
 lcd.print(sterlin()); */
 //euro
       /*lcd.home();
      lcd.print("Euro-TL");
      lcd.setCursor(4, 1);
      lcd.print(euro());*/
    if (Serial.available()) 
    {  
        data = Serial.read();  
        if (data == 'A') 
        {
          lcd.clear();  
          lcd.home();
          lcd.print("Euro-TL");
          lcd.setCursor(4, 1);
          lcd.print(euro());
          Serial.println(";");
          Serial.print(euro());
        } 
        else if(data=='B')
        {
          lcd.clear();
          lcd.home();
          lcd.print("Sterlin-TL");
          lcd.setCursor(4, 1);
          lcd.print(sterlin());
          Serial.println(";");
          Serial.print(sterlin());
        }    
        else if(data=='C')
        {  
          lcd.clear();
          lcd.home();
          lcd.print("Dolar-TL");
          lcd.setCursor(4, 1);
          lcd.print(dolar());
          Serial.println(";");
          Serial.print(dolar());
        }
        else if(data=='D')
        {
          lcd.clear();  
          lcd.home();
          lcd.print("Altin(gr)-TL");
          lcd.setCursor(4, 1);
          lcd.print(gramaltin());
          Serial.println(";");
          Serial.print(gramaltin());
        }      
    }  


  Serial.println("Baglanti kapatildi");
  esp.println("AT+CIPCLOSE");  //baglanti kapatma komutu
  delay(1000);
}

//euro api fonksiyonu
String euro() {
  String rest = "AT+CIPSEND=90";  //gonderilecek karakter sayisi
  rest += "\r\n";
  sendData(rest, 2000, 0);  //2 saniye
  String hostt = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=R6I3CZKNFFO4Y8T0";
  hostt += "\r\n";  //icindeki veri temizlenir ve yeni satira gecer.
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Euro = sendData(hostt, 2000, 1);

  //gelen verinin icinden sadece 2.spandeki euro degeri bilgisi alinir.
  int baslangic = Euro.indexOf(':');
  Euro = Euro.substring(baslangic + 1, baslangic + 8);

  return (Euro);
}
//sterlin api fonksiyonu
String sterlin() {
  String rest = "AT+CIPSEND=90";  //gonderilecek karakter sayisi
  rest += "\r\n";
  sendData(rest, 2000, 0);  //2 saniye
  String hostt = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=J2GDPDMC40T07KV0";
  hostt += "\r\n";  //icindeki veri temizlenir ve yeni satira gecer.
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Sterlin = sendData(hostt, 2000, 1);

  //gelen verinin icinden sadece 2.spandeki sterlin degeri bilgisi alinir.
  int baslangic = Sterlin.indexOf(':');
  Sterlin = Sterlin.substring(baslangic + 1, baslangic + 8);

  return (Sterlin);
}

String dolar() {
  String rest = "AT+CIPSEND=90";  //gonderilecek karakter sayisi
  rest += "\r\n";
  sendData(rest, 2000, 0);  //2 saniye
  String hostt = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=98GWZS3X1L2GQ0VA";
  hostt += "\r\n";  //icindeki veri temizlenir ve yeni satira gecer.
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Dolar = sendData(hostt, 2000, 1);

  //gelen verinin icinden sadece 2.spandeki sterlin degeri bilgisi alinir.
  int baslangic = Dolar.indexOf(':');
  Dolar = Dolar.substring(baslangic + 1, baslangic + 8);

  return (Dolar);
}

String gramaltin() {
  String rest = "AT+CIPSEND=90";  //gonderilecek karakter sayisi
  rest += "\r\n";
  sendData(rest, 2000, 0);  //2 saniye
  String hostt = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=BPQF0U7WBWVYHZT8";
  hostt += "\r\n";  //icindeki veri temizlenir ve yeni satira gecer.
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Altin = sendData(hostt, 2000, 1);

  //gelen verinin icinden sadece 2.spandeki altin degeri bilgisi alinir.
  int baslangic = Altin.indexOf(':');
  Altin = Altin.substring(baslangic + 1, baslangic + 8);

  return (Altin);
}

//euro verisini okuma ve dondurme
String sendData(String komut, const int gecenzaman, boolean debug) {
  String response = "";

  esp.print(komut);           //komut satirini(rest) espnin cikisina yazilir
  long int Zaman = millis();  //zamanin gecmesni bekler

  while ((Zaman + gecenzaman) > millis()) {
    while (esp.available())  //espnin baglantisindan gelen veri var ise
    {
      char c = esp.read();  // her bir karakter okunu c'ye yazilir
      response += c;        //cdeki veriler response degiskenine yazilir.
    }
  }
  /*if(debug) //hata olursa
  {
    Serial.print(response);//31,6279
  }*/
  return response;  //31,6279
}
