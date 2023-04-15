// Połączenie do RemoteMe
#define WIFI_NAME "SSID"
#define WIFI_PASSWORD "PASSWORD"
#define DEVICE_ID 1
#define DEVICE_NAME "Nazwa urzadzenia podana na portalu"
#define TOKEN "Token komunikacyjny z portalu Remoteme.org"

#include <RemoteMe.h>
#include <RemoteMeSocketConnector.h>
RemoteMe& remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

inline void setGoscie_set(int32_t i) {remoteMe.getVariables()->setInteger("Goscie_set", i); }
inline void setGoscie_wynik(int32_t i) {remoteMe.getVariables()->setInteger("Goscie_wynik", i); }
inline void setGospodarze_set(int32_t i) {remoteMe.getVariables()->setInteger("Gospodarze_set", i); }
inline void setGospodarze_wynik(int32_t i) {remoteMe.getVariables()->setInteger("Gospodarze_wynik", i); }
inline void setSet(int32_t i) {remoteMe.getVariables()->setInteger("Set", i); }
inline void setMinuta1(int32_t i) {remoteMe.getVariables()->setInteger("Minuta1", i); }
inline void setMinuta2(int32_t i) {remoteMe.getVariables()->setInteger("Minuta2", i); }
inline void setSekunda1(int32_t i) {remoteMe.getVariables()->setInteger("Sekunda1", i); }
inline void setSekunda2(int32_t i) {remoteMe.getVariables()->setInteger("Sekunda2", i); }
inline void setGoscie_czas(int32_t i) {remoteMe.getVariables()->setInteger("Goscie_czas", i); }
inline void setGospodarze_czas(int32_t i) {remoteMe.getVariables()->setInteger("Gospodarze_czas", i); }

void onGoscie_setChange(int32_t i) {
}
void onGoscie_wynikChange(int32_t i) {
}
void onGospodarze_setChange(int32_t i) {
}
void onGospodarze_wynikChange(int32_t i) {
}
void onSetChange(int32_t i) {
}
void onMinuta1Change(int32_t i) {
}
void onMinuta2Change(int32_t i) {
}
void onSekunda1Change(int32_t i) {
}
void onSekunda2Change(int32_t i) {
}
void onGoscie_czasChange(int32_t i) {
}
void onGospodarze_czasChange(int32_t i) {
}
// Załadowanie bibliotek
#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif
#define PIN        D1
#define NUMPIXELS 203
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Połączenie sieciowe
const char* ssid     = WIFI_NAME;
const char* password = WIFI_PASSWORD;

// Ustawienie odpowiedniego portu serwera
WiFiServer server(80);

// Zmienna przechowujaca żądania HTTP
String header;

// Ustawienie stanów zmiennych odpowiedzialnych za zmiany wyników
 String gospPlState = "off";
 String gospMiState = "off";
 String gospSetPlState = "off";
 String gospSetMiState = "off";
 String goscPlState = "off";
 String goscMiState = "off";
 String goscSetPlState = "off";
 String goscSetMiState = "off";
 String punktyReset = "off";
 String gospodarzeCzas = "off";
 String goscieCzas = "off";
 String startCzas = "off";
 String stopCzas = "off";
 String pauzaCzas = "off";

// Zmienne odpowiedzialne za przebieg meczu oraz konfiguracje wyswietlacza 
unsigned short gosp = 0;
unsigned short gosc = 0;
unsigned short gosp_set = 0;
unsigned short gosp_set_modulo = gosp_set%10;
unsigned short gosc_set = 0;
unsigned short gosc_set_modulo = gosp_set%10;
unsigned short czesc_gry = 0;
unsigned short czesc_gry_modulo = czesc_gry%10;
unsigned long aktualnyCzas=0;
unsigned long zapamietanyCzas=0;
unsigned long roznicaCzasu=0;
unsigned short kolor1 = 255;
unsigned short kolor2 = 0;
unsigned short kolor3 = 0;
unsigned short kolorGosc1 = 0;
unsigned short kolorGosc2 = 255;
unsigned short kolorGosc3 = 0;
unsigned short kolorSetGosp1 = 255;
unsigned short kolorSetGosp2 = 0;
unsigned short kolorSetGosp3 = 0;
unsigned short kolorSetGosc1 = 255;
unsigned short kolorSetGosc2 = 0;
unsigned short kolorSetGosc3 = 0;
unsigned short kolorSet1 = 255;
unsigned short kolorSet2 = 0;
unsigned short kolorSet3 = 0;
short gospCzas = 2;
short goscCzas = 2;

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

// ***********************************Definicja segmentow*********************************
void segment1(){
for (int i=0;i<5;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment2(){
for (int i=5;i<10;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment3(){
for (int i=10;i<15;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment4(){
for (int i=15;i<20;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment5(){
for (int i=20;i<25;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment6(){
for (int i=25;i<30;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment7(){
for (int i=30;i<35;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment8(){
for (int i=35;i<40;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment9(){
for (int i=40;i<45;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment10(){
for (int i=45;i<50;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment11(){
for (int i=50;i<55;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment12(){
for (int i=55;i<60;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment13(){
for (int i=60;i<65;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment14(){
for (int i=65;i<70;i++){
pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
}};
void segment15(){
for (int i=70;i<75;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment16(){
for (int i=75;i<80;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment17(){
for (int i=80;i<85;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment18(){
for (int i=85;i<90;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment19(){
for (int i=90;i<95;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment20(){
for (int i=95;i<100;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment21(){
for (int i=100;i<105;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment22(){
for (int i=105;i<110;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment23(){
for (int i=110;i<115;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment24(){
for (int i=115;i<120;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment25(){
for (int i=120;i<125;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment26(){
for (int i=125;i<130;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment27(){
for (int i=130;i<135;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment28(){
for (int i=135;i<140;i++){
pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
}};
void segment29(){
for (int i=140;i<143;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment30(){
for (int i=143;i<146;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment31(){
for (int i=146;i<149;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment32(){
for (int i=149;i<152;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment33(){
for (int i=152;i<155;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment34(){
for (int i=155;i<158;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment35(){
for (int i=158;i<161;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
}};
void segment36(){
for (int i=161;i<164;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment37(){
for (int i=164;i<167;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment38(){
for (int i=167;i<170;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment39(){
for (int i=170;i<173;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment40(){
for (int i=173;i<176;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment41(){
for (int i=176;i<179;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment42(){
for (int i=179;i<182;i++){
pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
}};
void segment43(){
for (int i=182;i<185;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment44(){
for (int i=185;i<188;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment45(){
for (int i=188;i<191;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment46(){
for (int i=191;i<194;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment47(){
for (int i=194;i<197;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment48(){
for (int i=197;i<200;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};
void segment49(){
for (int i=200;i<203;i++){
pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
}};

//****************************************************************************************

void setup() {
  Serial.begin(74880);
  // Łączenie z siecią bezprzewodową
  Serial.print("Laczenie z siecia: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
   pixels.begin();
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  remoteMe.getVariables()->observeInteger("Goscie_set" ,onGoscie_setChange);
  remoteMe.getVariables()->observeInteger("Goscie_wynik" ,onGoscie_wynikChange);
  remoteMe.getVariables()->observeInteger("Gospodarze_set" ,onGospodarze_setChange);
  remoteMe.getVariables()->observeInteger("Gospodarze_wynik" ,onGospodarze_wynikChange);
  remoteMe.getVariables()->observeInteger("Set" ,onSetChange);
  remoteMe.getVariables()->observeInteger("Minuta1" ,onMinuta1Change);
  remoteMe.getVariables()->observeInteger("Minuta2" ,onMinuta2Change);
  remoteMe.getVariables()->observeInteger("Sekunda1" ,onSekunda1Change);
  remoteMe.getVariables()->observeInteger("Sekunda2" ,onSekunda2Change);
  remoteMe.getVariables()->observeInteger("Goscie_czas" ,onGoscie_czasChange);
  remoteMe.getVariables()->observeInteger("Gospodarze_czas" ,onGospodarze_czasChange);
  remoteMe.setConnector(new RemoteMeSocketConnector());
  remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}

void loop(){
    pixels.clear();
  czesc_gry=gosp_set+gosc_set+1;
  if (czesc_gry==5){
    gospCzas = 1;
    goscCzas = 1;
    }
  if (gospCzas < 0){
    gospCzas = 0;
    }
    if (goscCzas < 0){
    goscCzas = 0;
    }
  remoteMe.loop();

  if(gosp_set>=10 && gosp_set<=19){
     kolorSetGosp1=255;
     kolorSetGosp2=0;
     kolorSetGosp3=0;   
  }
  else if(gosp_set>=20 && gosp_set<=29){
     kolorSetGosp1=0;
     kolorSetGosp2=255;
     kolorSetGosp3=14;   
  }
    else if(gosp_set>=30 && gosp_set<=39){
     kolorSetGosp1=17;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }
    else if(gosp_set>=40 && gosp_set<=49){
     kolorSetGosp1=255;
     kolorSetGosp2=255;
     kolorSetGosp3=69;   
  }
    else if(gosp_set>=50 && gosp_set<=59){
     kolorSetGosp1=255;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }
    else if(gosp_set>=60 && gosp_set<=69){
     kolorSetGosp1=0;
     kolorSetGosp2=255;
     kolorSetGosp3=255;   
  }
    else if(gosp_set>=70 && gosp_set<=79){
     kolorSetGosp1=170;
     kolorSetGosp2=32;
     kolorSetGosp3=235;   
  }
    else if(gosp_set>=80 && gosp_set<=89){
     kolorSetGosp1=20;
     kolorSetGosp2=194;
     kolorSetGosp3=235;   
  }
    else if(gosp_set>=90 && gosp_set<=99){
     kolorSetGosp1=0;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }

  if(gosc_set>=10 && gosc_set<=19){
     kolorSetGosp1=255;
     kolorSetGosp2=0;
     kolorSetGosp3=0;   
  }
  else if(gosc_set>=20 && gosc_set<=29){
     kolorSetGosp1=0;
     kolorSetGosp2=255;
     kolorSetGosp3=14;   
  }
    else if(gosc_set>=30 && gosc_set<=39){
     kolorSetGosp1=17;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }
    else if(gosc_set>=40 && gosc_set<=49){
     kolorSetGosp1=255;
     kolorSetGosp2=255;
     kolorSetGosp3=69;   
  }
    else if(gosc_set>=50 && gosc_set<=59){
     kolorSetGosp1=255;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }
    else if(gosc_set>=60 && gosc_set<=69){
     kolorSetGosp1=0;
     kolorSetGosp2=255;
     kolorSetGosp3=255;   
  }
    else if(gosc_set>=70 && gosc_set<=79){
     kolorSetGosp1=170;
     kolorSetGosp2=32;
     kolorSetGosp3=235;   
  }
    else if(gosc_set>=80 && gosc_set<=89){
     kolorSetGosp1=20;
     kolorSetGosp2=194;
     kolorSetGosp3=235;   
  }
    else if(gosc_set>=90 && gosc_set<=99){
     kolorSetGosp1=0;
     kolorSetGosp2=0;
     kolorSetGosp3=255;   
  }


switch(gosp){
            case 1:
      pixels.clear();
      segment10();
      segment14();
      pixels.show();
      break;
            case 2:
      pixels.clear();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      pixels.show();
      break;
            case 3:
      pixels.clear();
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      pixels.show();
      break;
            case 4:
      pixels.clear();
      segment8();
      segment11();
      segment10();
      segment14();
      pixels.show();
      break;
            case 5:
      pixels.clear();
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      pixels.show();
      break;
            case 6:
      pixels.clear();
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      pixels.show();
      break;
            case 7:
      pixels.clear();
      segment9();
      segment10();
      segment14();
      pixels.show();
      break;    
            case 8:
      pixels.clear();
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      pixels.show();
      break;
            case 9:
      pixels.clear();
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      pixels.show();
      break;
            case 10:
      pixels.clear();
      //****************10************************
      segment3();
      segment7();
      //******************************************
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 11:
      pixels.clear();
            //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 12:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 13:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 14:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 15:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 16:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 17:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 18:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 19:
      pixels.clear();
                  //****************10************************
      segment3();
      segment7();
      //******************************************
      
      //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 20:
      pixels.clear();
      //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 21:
      pixels.clear();
            //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 22:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 23:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 24:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 25:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 26:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 27:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 28:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 29:
      pixels.clear();
                  //***************20*************************
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      //******************************************
      
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 30:
      pixels.clear();
      //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 31:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 32:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 33:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 34:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 35:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 36:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 37:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 38:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 39:
      pixels.clear();
            //***************30*************************
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 40:
      pixels.clear();
      //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 41:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 42:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 43:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 44:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break; 
            case 45:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 46:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 47:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
      //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 48:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 49:
      pixels.clear();
            //***************40*************************
      segment1();
      segment3();
      segment4();
      segment7();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 50:
      pixels.clear();
      //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 51:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 52:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 53:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 54:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 55:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 56:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 57:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 58:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 59:
      pixels.clear();
            //****************50************************
      segment2();
      segment1();
      segment4();
      segment7();
      segment6();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 60:
      pixels.clear();
      //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 61:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 62:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 63:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 64:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 65:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 66:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 67:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 68:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 69:
      pixels.clear();
            //****************60************************
      segment2();
      segment1();
      segment5();
      segment6();
      segment7();
      segment4();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 70:
      pixels.clear();
      //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
      
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 71:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 72:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 73:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 74:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 75:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 76:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 77:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 78:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 79:
      pixels.clear();
            //****************70************************
      segment2();
      segment3();
      segment7();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 80:
      pixels.clear();
      //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 81:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 82:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 83:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 84:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 85:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 86:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 87:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 88:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 89:
      pixels.clear();
            //***************80*************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment5();
      segment6();
      segment7();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 90:
      pixels.clear();
      //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 91:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
      //***************1**************************
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 92:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //**************2***************************
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 93:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //*************3****************************
      segment9();
      segment10();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 94:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //************4*****************************
      segment8();
      segment11();
      segment10();
      segment14();
      //******************************************
      pixels.show();
      break;
            case 95:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //****************5*************************
      segment9();
      segment8();
      segment11();
      segment14();
      segment13();
      //******************************************
      pixels.show();
      break;
            case 96:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //****************6************************
      segment9();
      segment8();
      segment12();
      segment13();
      segment14();
      segment11();
      //*****************************************
      pixels.show();
      break;
            case 97:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***************7*************************
      segment9();
      segment10();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 98:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***************8*************************
      segment8();
      segment9();
      segment10();
      segment11();
      segment12();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;
            case 99:
      pixels.clear();
            //****************90************************
      segment1();
      segment2();
      segment3();
      segment4();
      segment6();
      segment7();
      //******************************************
            //***********************9*****************
      segment8();
      segment9();
      segment10();
      segment11();
      segment13();
      segment14();
      //*****************************************
      pixels.show();
      break;

      default:
      pixels.clear(); // Set all pixel colors to 'off'
      //****************0*************************
      segment8();
      segment9();
      segment10();
      segment12();
      segment14();
      //******************************************
      gosp=0;
      break;
}
switch(gosc){
            case 1:
      pixels.clear();
      segment24();
      segment28();
      pixels.show();
      break;
            case 2:
      pixels.clear();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      pixels.show();
      break;
            case 3:
      pixels.clear();
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      pixels.show();
      break;
            case 4:
      pixels.clear();
      segment22();
      segment25();
      segment24();
      segment28();
      pixels.show();
      break;
            case 5:
      pixels.clear();
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      pixels.show();
      break;
            case 6:
      pixels.clear();
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      pixels.show();
      break;
            case 7:
      pixels.clear();
      segment23();
      segment24();
      segment28();
      pixels.show();
      break;    
            case 8:
      pixels.clear();
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      pixels.show();
      break;
            case 9:
      pixels.clear();
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      pixels.show();
      break;
            case 10:
      pixels.clear();
      //****************10************************
      segment17();
      segment11();
      //******************************************
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 11:
      pixels.clear();
            //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 12:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 13:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 14:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 15:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 16:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 17:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 18:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 19:
      pixels.clear();
                  //****************10************************
      segment17();
      segment11();
      //******************************************
      
      //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 20:
      pixels.clear();
      //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 21:
      pixels.clear();
            //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 22:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 23:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 24:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 25:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 26:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 27:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 28:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 29:
      pixels.clear();
                  //***************20*************************
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      //******************************************
      
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 30:
      pixels.clear();
      //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 31:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 32:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 33:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 34:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 35:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 36:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 37:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 38:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 39:
      pixels.clear();
            //***************30*************************
      segment16();
      segment17();
      segment18();
      segment20();
      segment21();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 40:
      pixels.clear();
      //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 41:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 42:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 43:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 44:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break; 
            case 45:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 46:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 47:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
      //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 48:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 49:
      pixels.clear();
            //***************40*************************
      segment15();
      segment17();
      segment18();
      segment21();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 50:
      pixels.clear();
      //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 51:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 52:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 53:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 54:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 55:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 56:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 57:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 58:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 59:
      pixels.clear();
            //****************50************************
      segment16();
      segment15();
      segment18();
      segment21();
      segment20();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 60:
      pixels.clear();
      //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 61:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 62:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 63:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 64:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 65:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 66:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 67:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 68:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 69:
      pixels.clear();
            //****************60************************
      segment16();
      segment15();
      segment19();
      segment20();
      segment21();
      segment18();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 70:
      pixels.clear();
      //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
      
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 71:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 72:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 73:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 74:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 75:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 76:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 77:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 78:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 79:
      pixels.clear();
            //****************70************************
      segment16();
      segment17();
      segment21();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 80:
      pixels.clear();
      //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 81:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 82:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 83:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 84:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 85:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 86:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 87:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 88:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 89:
      pixels.clear();
            //***************80*************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment19();
      segment20();
      segment21();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 90:
      pixels.clear();
      //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 91:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
      //***************1**************************
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 92:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //**************2***************************
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 93:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //*************3****************************
      segment23();
      segment24();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 94:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //************4*****************************
      segment22();
      segment25();
      segment24();
      segment28();
      //******************************************
      pixels.show();
      break;
            case 95:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //****************5*************************
      segment23();
      segment22();
      segment25();
      segment28();
      segment27();
      //******************************************
      pixels.show();
      break;
            case 96:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //****************6************************
      segment23();
      segment22();
      segment26();
      segment27();
      segment28();
      segment25();
      //*****************************************
      pixels.show();
      break;
            case 97:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //***************7*************************
      segment23();
      segment24();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 98:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //***************8*************************
      segment22();
      segment23();
      segment24();
      segment25();
      segment26();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;
            case 99:
      pixels.clear();
            //****************90************************
      segment15();
      segment16();
      segment17();
      segment18();
      segment20();
      segment22();
      //******************************************
            //***********************9*****************
      segment22();
      segment23();
      segment24();
      segment25();
      segment27();
      segment28();
      //*****************************************
      pixels.show();
      break;

      default:
      pixels.clear(); // Set all pixel colors to 'off'
      //****************0*************************
      segment22();
      segment23();
      segment24();
      segment26();
      segment28();
      //******************************************
      gosc=0;
      break;
}
switch(gosp_set){
            case 1:
      segment43();
      segment47();
      pixels.show();
      break;
            case 2:
      pixels.clear();
      segment44();
      segment43();
      segment46();
      segment47();
      segment48();
      pixels.show();
      break;
            case 3:
      pixels.clear();
      segment44();
      segment43();
      segment46();
      segment47();
      segment48();
      pixels.show();
      break;
            case 4:
      pixels.clear();
      segment45();
      segment46();
      segment43();
      segment47();
      pixels.show();
      break;
            case 5:
      pixels.clear();
            segment44();
            segment45();
            segment46();
            segment47();
            segment48();
      pixels.show();
      break;
            case 6:
      pixels.clear();
            segment44();
            segment45();
            segment49();
            segment48();
            segment47();
            segment46();
      pixels.show();
      break;
            case 7:
      pixels.clear();
            segment44();
            segment43();
            segment47();
      pixels.show();
      break;    
            case 8:
      pixels.clear();
            segment43();
            segment44();
            segment45();
            segment46();
            segment47();
            segment48();
            segment49();
      pixels.show();
      break;
            case 9:
      pixels.clear();
            segment43();
            segment44();
            segment45();
            segment46();
            segment47();
            segment48();
      pixels.show();
      break;
            default:
      pixels.clear(); // Set all pixel colors to 'off'
      gosp_set_modulo=0;
      break;
}
switch(gosc_set){
            case 1:
      segment29();
      segment33();
      pixels.show();
      break;
            case 2:
      pixels.clear();
      segment30();
      segment29();
      segment32();
      segment35();
      segment34();
      pixels.show();
      break;
            case 3:
      pixels.clear();
      segment30();
      segment29();
      segment32();
      segment33();
      segment34();
      pixels.show();
      break;
            case 4:
      pixels.clear();
      segment31();
      segment32();
      segment29();
      segment33();
      pixels.show();
      break;
            case 5:
      pixels.clear();
      segment30();
      segment31();
      segment32();
      segment33();
      segment34();
      pixels.show();
      break;
            case 6:
      pixels.clear();
      segment30();
      segment31();
      segment32();
      segment35();
      segment34();
      segment33();
      pixels.show();
      break;
            case 7:
      pixels.clear();
      segment30();
      segment29();
      segment33();
      pixels.show();
      break;    
            case 8:
      pixels.clear();
      segment29();
      segment30();
      segment31();
      segment32();
      segment33();
      segment34();
      segment35();
      pixels.show();
      break;
            case 9:
      pixels.clear();
      segment29();
      segment30();
      segment31();
      segment32();
      segment33();
      segment34();
      pixels.show();
      break;
            default:
      pixels.clear(); // Set all pixel colors to 'off'
      gosc_set_modulo=0;
      break;
}
switch(czesc_gry){
            case 1:
      segment36();
      segment40();
      pixels.show();
      break;
            case 2:
      pixels.clear();
      segment37();
      segment36();
      segment39();
      segment42();
      segment41();
      pixels.show();
      break;
            case 3:
      pixels.clear();
      segment37();
      segment36();
      segment39();
      segment40();
      segment41();
      pixels.show();
      break;
            case 4:
      pixels.clear();
      segment38();
      segment39();
      segment36();
      segment40();
      pixels.show();
      break;
            case 5:
      pixels.clear();
      segment37();
      segment38();
      segment39();
      segment40();
      segment41();
      pixels.show();
      break;
            case 6:
      pixels.clear();
      segment37();
      segment38();
      segment39();
      segment40();
      segment41();
      segment42();
      pixels.show();
      break;
            case 7:
      pixels.clear();
      segment37();
      segment36();
      segment40();
      pixels.show();
      break;    
            case 8:
      pixels.clear();
      segment36();
      segment37();
      segment38();
      segment39();
      segment40();
      segment41();
      segment42();
      pixels.show();
      break;
            case 9:
      pixels.clear();
      segment36();
      segment37();
      segment38();
      segment39();
      segment40();
      segment41();
      pixels.show();
      break;
            default:
      pixels.clear();
      czesc_gry_modulo=0;
      break;
}
  WiFiClient client = server.available();   
  if (client) {                            
    Serial.println("Nowy klient.");         
    String currentLine = "";              
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();         
      if (client.available()) {            
        char c = client.read();            
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            if (header.indexOf("GET /gosp+/on") >= 0) {
              Serial.println("Gosp+ on");
              gospPlState = "on";
            } else if (header.indexOf("GET /gosp+/off") >= 0) {
              Serial.println("Gosp+ off");
              gospPlState = "off";
            }else if (header.indexOf("GET /gosp-/on") >= 0) {
              Serial.println("Gosp- on");
              gospMiState = "on";
            } else if (header.indexOf("GET /gosp-/off") >= 0) {
              Serial.println("Gosp- off");
              gospMiState = "off";
            } else if (header.indexOf("GET /gosp_set+/on") >= 0) {
              Serial.println("Gosp_set+ on");
              gospSetPlState = "on";
            } else if (header.indexOf("GET /gosp_set+/off") >= 0) {
              Serial.println("Gosp_set+ off");
              gospSetPlState = "off";
            }
            else if (header.indexOf("GET /gosp_set-/on") >= 0) {
              Serial.println("Gosp_set- on");
              gospSetMiState = "on";
            } else if (header.indexOf("GET /gosp_set-/off") >= 0) {
              Serial.println("Gosp_set- off");
              gospSetMiState = "off";
            }
            else if (header.indexOf("GET /punktyReset/on") >= 0) {
              Serial.println("punktyReset on");
              punktyReset = "on";
            } else if (header.indexOf("GET /punktyReset/off") >= 0) {
              Serial.println("punktyReset off");
              punktyReset = "off";
            }else if (header.indexOf("GET /gospodarzeCzas/on") >= 0) {
              Serial.println("gospodarzeCzas on");
              gospodarzeCzas = "on";
            } else if (header.indexOf("GET /gospodarzeCzas/off") >= 0) {
              Serial.println("gospodarzeCzas off");
              gospodarzeCzas = "off";}
              else if (header.indexOf("GET /goscieCzas/on") >= 0) {
              Serial.println("goscieCzas on");
              goscieCzas = "on";
            } else if (header.indexOf("GET /goscieCzas/off") >= 0) {
              Serial.println("goscieCzas off");
              goscieCzas = "off";
            }else if (header.indexOf("GET /gosc+/on") >= 0) {
              Serial.println("Gosc+ on");
              goscPlState = "on";
            } else if (header.indexOf("GET /gosc+/off") >= 0) {
              Serial.println("Gosc+ off");
              goscPlState = "off";
            } else if (header.indexOf("GET /gosc-/on") >= 0) {
              Serial.println("Gosc- on");
              goscMiState = "on";
            } else if (header.indexOf("GET /gosc-/off") >= 0) {
              Serial.println("Gosc- off");
              goscMiState = "off";
            }else if (header.indexOf("GET /gosc_set+/on") >= 0) {
              Serial.println("Gosc_set+ on");
              goscSetPlState = "on";
            } else if (header.indexOf("GET /gosc_set+/off") >= 0) {
              Serial.println("Gosc_set+ off");
              goscSetPlState = "off";
            }else if (header.indexOf("GET /gosc_set-/on") >= 0) {
              Serial.println("Gosc_set- on");
              goscSetMiState = "on";
            } else if (header.indexOf("GET /gosc_set-/off") >= 0) {
              Serial.println("Gosc_set- off");
              goscSetMiState = "off";
            }
            // Strona z panelem sterowania
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
        //    client.println("<head> <meta http-equiv=\"refresh\" content=\"30\"></head>");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button {");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".gospodarze {margin:2px;float:left;}");
            client.println(".button2 {background-color: #77878A;}");
            client.println(".czysciciel {clear:both;}</style></head>");
            
            
            client.println("<body><center><h1>Panel sterowania </h1></center>");
            
           client.println("<hr>");
           client.println("<p>Gospodarze</p>");      
            if (gospPlState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp+/on\"><button class=\"button\">Punkt+</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp+/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosp++;
            } 
            
            // If the output4State is off, it displays the ON button       
            if (gospMiState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp-/on\"><button class=\"button\">Punkt-</button></a></p>");
             
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp-/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosp--;
            }
                
            if (gospSetPlState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp_set+/on\"><button class=\"button\">Set+</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp_set+/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosp_set++;
            }        
            if (gospSetMiState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp_set-/on\"><button class=\"button\">Set-</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosp_set-/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosp_set--;
            } 
           client.println("<p class=\"czysciciel\"></p>"); 
           client.println("<hr>");           
           client.println("<p>Reset / Obsluga spotkania</p>");
            if (punktyReset=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/punktyReset/on\"><button class=\"button\">Reset</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/punktyReset/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosp=0;
              gosc=0;
              gosp_set=0;
              gosc_set=0;
              gospCzas=0;
              goscCzas=0;
              sekunda2=0;
              sekunda1=0;
              minuta2=0;
              minuta1=0;
            }    
            if (gospodarzeCzas=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gospodarzeCzas/on\"><button class=\"button\">Gosp - Czas</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gospodarzeCzas/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gospCzas--;
            } 
                        if (goscieCzas=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/goscieCzas/on\"><button class=\"button\">Gosc - Czas</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/goscieCzas/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gospCzas--;
            } 
                        
            client.println("<p class=\"czysciciel\"></p>");
            client.println("<hr>");
            client.println("<p>Goscie</p>");

                        if (goscPlState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc+/on\"><button class=\"button\">Punkt+</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc+/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosc++;
            } 
     
            if (goscMiState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc-/on\"><button class=\"button\">Punkt-</button></a></p>");
             
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc-/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosc--;
            }
                
            if (goscSetPlState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc_set+/on\"><button class=\"button\">Set+</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc_set+/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosc_set++;
            }       
            if (goscSetMiState=="off") {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc_set-/on\"><button class=\"button\">Set-</button></a></p>");
              
            } else {
              client.println("<p class=\"gospodarze\"><a href=\"/gosc_set-/off\"><button class=\"button button2\">Zatwierdz</button></a></p>");
              gosc_set--;
            }  
            client.println("<p class=\"czysciciel\"></p>"); 
                       client.println("<hr>");
            client.println("<p>Gospodarze: </p>");
            client.println(gosp);
                        client.println("<p>Goscie: </p>");
            client.println(gosc);
                        client.println("<p>Gospodarze - Set: </p>");
            client.println(gosp_set);
                        client.println("<p>Set: </p>");
            client.println(czesc_gry);
            client.println("<p>Goscie - Set: </p>");
            client.println(gosc_set);
            client.println("<p>Gospodarze - Pozostale czasy: </p>");
            client.println(gospCzas);
            client.println("<p>Goscie - Pozostale czasy: </p>");
            client.println(goscCzas);
            client.println("</body></html>");
            
            client.println();
            break;
          } else {
            currentLine = "";
          }
        }         else if (c != '\r') {  
          currentLine += c;     
        }
      }
    }

    header = "";
    client.stop();
    Serial.println("Rozłączono klienta.");
    Serial.println("");

  }
            static long time=millis();
    if (time+700<millis()){
      time=millis();
      setGospodarze_wynik(gosp);
      setGoscie_wynik(gosc);
      setGospodarze_set(gosp_set);
      setGoscie_set(gosc_set);
      setSet(czesc_gry);
      setMinuta1(minuta1);
      setMinuta2(minuta2);
      setSekunda1(sekunda1);
      setSekunda2(sekunda2);
      setGospodarze_czas(gospCzas);
      setGoscie_czas(goscCzas);
    }
}
