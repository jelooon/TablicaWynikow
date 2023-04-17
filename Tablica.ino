// Połączenie z RemoteMe
#define WIFI_NAME "SSID"
#define WIFI_PASSWORD "PASSWORD"
#define DEVICE_ID 1
#define DEVICE_NAME "ESP"
#define TOKEN "TOKENFROMSERVICE"
#include <ESP8266WiFi.h>       // Biblioteka umożliwiająca komunikację z siecią bezprzewodową
#include <Adafruit_NeoPixel.h> // Biblioteka odpowiedzialna za obsługę diod LED
#include <RemoteMe.h>          // Biblioteka odpowiedzialna za łączność z portalem remoteme.org
#include <RemoteMeSocketConnector.h>
RemoteMe &remoteMe = RemoteMe::getInstance(TOKEN, DEVICE_ID);

inline void setGoscie_set(int32_t i) { remoteMe.getVariables()->setInteger("Goscie_set", i); }
inline void setGoscie_wynik(int32_t i) { remoteMe.getVariables()->setInteger("Goscie_wynik", i); }
inline void setGospodarze_set(int32_t i) { remoteMe.getVariables()->setInteger("Gospodarze_set", i); }
inline void setGospodarze_wynik(int32_t i) { remoteMe.getVariables()->setInteger("Gospodarze_wynik", i); }
inline void setSet(int32_t i) { remoteMe.getVariables()->setInteger("Set", i); }
inline void setMinuta1(int32_t i) { remoteMe.getVariables()->setInteger("Minuta1", i); }
inline void setMinuta2(int32_t i) { remoteMe.getVariables()->setInteger("Minuta2", i); }
inline void setSekunda1(int32_t i) { remoteMe.getVariables()->setInteger("Sekunda1", i); }
inline void setSekunda2(int32_t i) { remoteMe.getVariables()->setInteger("Sekunda2", i); }
inline void setGoscie_czas(int32_t i) { remoteMe.getVariables()->setInteger("Goscie_czas", i); }
inline void setGospodarze_czas(int32_t i) { remoteMe.getVariables()->setInteger("Gospodarze_czas", i); }
inline void setGoscSet1(int32_t i) { remoteMe.getVariables()->setInteger("GoscSet1", i); }
inline void setGoscSet2(int32_t i) { remoteMe.getVariables()->setInteger("GoscSet2", i); }
inline void setGoscSet3(int32_t i) { remoteMe.getVariables()->setInteger("GoscSet3", i); }
inline void setGoscSet4(int32_t i) { remoteMe.getVariables()->setInteger("GoscSet4", i); }
inline void setGoscSet5(int32_t i) { remoteMe.getVariables()->setInteger("GoscSet5", i); }
inline void setGospSet1(int32_t i) { remoteMe.getVariables()->setInteger("GospSet1", i); }
inline void setGospSet2(int32_t i) { remoteMe.getVariables()->setInteger("GospSet2", i); }
inline void setGospSet3(int32_t i) { remoteMe.getVariables()->setInteger("GospSet3", i); }
inline void setGospSet4(int32_t i) { remoteMe.getVariables()->setInteger("GospSet4", i); }
inline void setGospSet5(int32_t i) { remoteMe.getVariables()->setInteger("GospSet5", i); }
inline void setGospodarze_nazwa(String s) { remoteMe.getVariables()->setText("Gospodarze_nazwa", s); }
inline void setGoscie_nazwa(String s) { remoteMe.getVariables()->setText("Goscie_nazwa", s); }
inline void setZagrywajacy(String s) { remoteMe.getVariables()->setText("Zagrywajacy", s); }

void onGoscie_setChange(int32_t i)
{
}
void onGoscie_wynikChange(int32_t i)
{
}
void onGospodarze_setChange(int32_t i)
{
}
void onGospodarze_wynikChange(int32_t i)
{
}
void onSetChange(int32_t i)
{
}
void onMinuta1Change(int32_t i)
{
}
void onMinuta2Change(int32_t i)
{
}
void onSekunda1Change(int32_t i)
{
}
void onSekunda2Change(int32_t i)
{
}
void onGoscie_czasChange(int32_t i)
{
}
void onGospodarze_czasChange(int32_t i)
{
}
void onGoscSet1Change(int32_t i)
{
}
void onGoscSet2Change(int32_t i)
{
}
void onGoscSet3Change(int32_t i)
{
}
void onGoscSet4Change(int32_t i)
{
}
void onGoscSet5Change(int32_t i)
{
}
void onGospSet1Change(int32_t i)
{
}
void onGospSet2Change(int32_t i)
{
}
void onGospSet3Change(int32_t i)
{
}
void onGospSet4Change(int32_t i)
{
}
void onGospSet5Change(int32_t i)
{
}
void onGospodarze_nazwaChange(String s)
{
}
void onGoscie_nazwaChange(String s)
{
}
void onZagrywajacyChange(String s)
{
}

//Konfiguracja połączenia z mikrokontrolerem
#define PIN D1
#define NUMPIXELS 209
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Połączenie sieciowe
const char *ssid = WIFI_NAME;
const char *password = WIFI_PASSWORD;
WiFiServer server(80);
// Zmienne wykorzystywane do obsługi żądań HTTP
String header;
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
String zamienStrony = "off";
String startCzas = "off";
String stopCzas = "off";
String pauzaCzas = "off";
// Zmienne wykorzystywane do prezentacji wyników
String GospodarzeRezerwa = "Gospodarze";
String GoscieRezerwa = "Goscie";
unsigned short gosp = 0;
unsigned short gosc = 0;
unsigned short gosp_set = 0;
unsigned short gosp_set_modulo = gosp_set % 10;
unsigned short gosc_set = 0;
unsigned short gosc_set_modulo = gosp_set % 10;
unsigned short czesc_gry = 0;
unsigned short czesc_gry_modulo = czesc_gry % 10;
unsigned short kolor1 = 255;
unsigned short kolor2 = 0;
unsigned short kolor3 = 0;
unsigned short kolorGosc1 = 0;
unsigned short kolorGosc2 = 255;
unsigned short kolorGosc3 = 0;
unsigned short kolorSetGosp1 = 255;
unsigned short kolorSetGosp2 = 0;
unsigned short kolorSetGosp3 = 0;
unsigned short kolorSetGosc1 = 0;
unsigned short kolorSetGosc2 = 255;
unsigned short kolorSetGosc3 = 0;
unsigned short kolorSet1 = 0;
unsigned short kolorSet2 = 255;
unsigned short kolorSet3 = 255;
unsigned short gospCzas = 2;
unsigned short goscCzas = 2;
unsigned short setStan = 1;
unsigned short gosp_set1 = 0;
unsigned short gosp_set2 = 0;
unsigned short gosp_set3 = 0;
unsigned short gosp_set4 = 0;
unsigned short gosp_set5 = 0;
unsigned short gosc_set1 = 0;
unsigned short gosc_set2 = 0;
unsigned short gosc_set3 = 0;
unsigned short gosc_set4 = 0;
unsigned short gosc_set5 = 0;
String readString;
String GospodarzeNazwa = "Druzyna1";
String GoscieNazwa = "Druzyna2";
String Zagrywka = " ";
bool tryb = 0;
bool zegar = 0;
bool zatrzymaj = 0;
unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

// ***********************************Definicja segmentow*********************************
void segment1()
{
      for (int i = 0; i < 5; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment2()
{
      for (int i = 5; i < 10; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment3()
{
      for (int i = 10; i < 15; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment4()
{
      for (int i = 15; i < 20; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment5()
{
      for (int i = 20; i < 25; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment6()
{
      for (int i = 25; i < 30; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment7()
{
      for (int i = 30; i < 35; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment8()
{
      for (int i = 35; i < 40; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment9()
{
      for (int i = 40; i < 45; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment10()
{
      for (int i = 45; i < 50; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment11()
{
      for (int i = 50; i < 55; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment12()
{
      for (int i = 55; i < 60; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment13()
{
      for (int i = 60; i < 65; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment14()
{
      for (int i = 65; i < 70; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolor1, kolor2, kolor3));
      }
};
void segment15()
{
      for (int i = 70; i < 75; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment16()
{
      for (int i = 75; i < 80; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment17()
{
      for (int i = 80; i < 85; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment18()
{
      for (int i = 85; i < 90; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment19()
{
      for (int i = 90; i < 95; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment20()
{
      for (int i = 95; i < 100; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment21()
{
      for (int i = 100; i < 105; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment22()
{
      for (int i = 105; i < 110; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment23()
{
      for (int i = 110; i < 115; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment24()
{
      for (int i = 115; i < 120; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment25()
{
      for (int i = 120; i < 125; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment26()
{
      for (int i = 125; i < 130; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment27()
{
      for (int i = 130; i < 135; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment28()
{
      for (int i = 135; i < 140; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorGosc1, kolorGosc2, kolorGosc3));
      }
};
void segment29()
{
      for (int i = 140; i < 143; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment30()
{
      for (int i = 143; i < 146; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment31()
{
      for (int i = 146; i < 149; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment32()
{
      for (int i = 149; i < 152; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment33()
{
      for (int i = 152; i < 155; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment34()
{
      for (int i = 155; i < 158; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment35()
{
      for (int i = 158; i < 161; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void segment36()
{
      for (int i = 161; i < 164; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment37()
{
      for (int i = 164; i < 167; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment38()
{
      for (int i = 167; i < 170; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment39()
{
      for (int i = 170; i < 173; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment40()
{
      for (int i = 173; i < 176; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment41()
{
      for (int i = 176; i < 179; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment42()
{
      for (int i = 179; i < 182; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSet1, kolorSet2, kolorSet3));
      }
};
void segment43()
{
      for (int i = 182; i < 185; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment44()
{
      for (int i = 185; i < 188; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment45()
{
      for (int i = 188; i < 191; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment46()
{
      for (int i = 191; i < 194; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment47()
{
      for (int i = 194; i < 197; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment48()
{
      for (int i = 197; i < 200; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment49()
{
      for (int i = 200; i < 203; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment50()
{
      for (int i = 203; i < 205; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
};
void segment51()
{
      for (int i = 206; i < 208; i++)
      {
            pixels.setPixelColor(i, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
};
void serwGosp()
{
      pixels.setPixelColor(205, pixels.Color(255, 255, 255));
};
void serwGosc()
{
      pixels.setPixelColor(208, pixels.Color(255, 255, 255));
};
// ***********************************Definicja wylaczenia segmentow*********************************
void segment1off()
{
      for (int i = 0; i < 5; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment2off()
{
      for (int i = 5; i < 10; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment3off()
{
      for (int i = 10; i < 15; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment4off()
{
      for (int i = 15; i < 20; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment5off()
{
      for (int i = 20; i < 25; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment6off()
{
      for (int i = 25; i < 30; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment7off()
{
      for (int i = 30; i < 35; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment8off()
{
      for (int i = 35; i < 40; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment9off()
{
      for (int i = 40; i < 45; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment10off()
{
      for (int i = 45; i < 50; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment11off()
{
      for (int i = 50; i < 55; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment12off()
{
      for (int i = 55; i < 60; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment13off()
{
      for (int i = 60; i < 65; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment14off()
{
      for (int i = 65; i < 70; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment15off()
{
      for (int i = 70; i < 75; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment16off()
{
      for (int i = 75; i < 80; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment17off()
{
      for (int i = 80; i < 85; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment18off()
{
      for (int i = 85; i < 90; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment19off()
{
      for (int i = 90; i < 95; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment20off()
{
      for (int i = 95; i < 100; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment21off()
{
      for (int i = 100; i < 105; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment22off()
{
      for (int i = 105; i < 110; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment23off()
{
      for (int i = 110; i < 115; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment24off()
{
      for (int i = 115; i < 120; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment25off()
{
      for (int i = 120; i < 125; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment26off()
{
      for (int i = 125; i < 130; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment27off()
{
      for (int i = 130; i < 135; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment28off()
{
      for (int i = 135; i < 140; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment29off()
{
      for (int i = 140; i < 143; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment30off()
{
      for (int i = 143; i < 146; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment31off()
{
      for (int i = 146; i < 149; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment32off()
{
      for (int i = 149; i < 152; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment33off()
{
      for (int i = 152; i < 155; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment34off()
{
      for (int i = 155; i < 158; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment35off()
{
      for (int i = 158; i < 161; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment36off()
{
      for (int i = 161; i < 164; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment37off()
{
      for (int i = 164; i < 167; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment38off()
{
      for (int i = 167; i < 170; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment39off()
{
      for (int i = 170; i < 173; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment40off()
{
      for (int i = 173; i < 176; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment41off()
{
      for (int i = 176; i < 179; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment42off()
{
      for (int i = 179; i < 182; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment43off()
{
      for (int i = 182; i < 185; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment44off()
{
      for (int i = 185; i < 188; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment45off()
{
      for (int i = 188; i < 191; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment46off()
{
      for (int i = 191; i < 194; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment47off()
{
      for (int i = 194; i < 197; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment48off()
{
      for (int i = 197; i < 200; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment49off()
{
      for (int i = 200; i < 203; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment50off()
{
      for (int i = 203; i < 205; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void segment51off()
{
      for (int i = 206; i < 208; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};
void serwGospoff()
{
      pixels.setPixelColor(205, pixels.Color(0, 0, 0));
};
void serwGoscoff()
{
      pixels.setPixelColor(208, pixels.Color(0, 0, 0));
};
void Tablicaoff()
{
      for (int i = 0; i < 203; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
};

void ZamienStrony()
{
      for (int i = 0; i < 209; i++)
      {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }

      float gosp_temp, gosc_temp, gosp_set_temp, gosc_set_temp, gospCzas_temp, goscCzas_temp, gosp_set1_temp, gosp_set2_temp, gosp_set3_temp, gosp_set4_temp, gosp_set5_temp,
          gosc_set1_temp, gosc_set2_temp, gosc_set3_temp, gosc_set4_temp, gosc_set5_temp;
      String GospodarzeNazwa_temp, GoscieNazwa_temp;
      gosp_temp = gosp;
      gosc_temp = gosc;
      gosp_set_temp = gosp_set;
      gosc_set_temp = gosc_set;
      gospCzas_temp = gospCzas;
      goscCzas_temp = goscCzas;
      gosp_set1_temp = gosp_set1;
      gosp_set2_temp = gosp_set2;
      gosp_set3_temp = gosp_set3;
      gosp_set4_temp = gosp_set4;
      gosp_set5_temp = gosp_set5;
      gosc_set1_temp = gosc_set1;
      gosc_set2_temp = gosc_set2;
      gosc_set3_temp = gosc_set3;
      gosc_set4_temp = gosc_set4;
      gosc_set5_temp = gosc_set5;
      GospodarzeNazwa_temp = GospodarzeNazwa;
      GoscieNazwa_temp = GoscieNazwa;

      gosp = gosc_temp;
      gosc = gosp_temp;
      gosp_set = gosc_set_temp;
      gosc_set = gosp_set_temp;
      gospCzas = goscCzas_temp;
      goscCzas = gospCzas_temp;
      gosp_set1 = gosc_set1_temp;
      gosp_set2 = gosc_set2_temp;
      gosp_set3 = gosc_set3_temp;
      gosp_set4 = gosc_set4_temp;
      gosp_set5 = gosc_set5_temp;
      gosc_set1 = gosp_set1_temp;
      gosc_set2 = gosp_set2_temp;
      gosc_set3 = gosp_set3_temp;
      gosc_set4 = gosp_set4_temp;
      gosc_set5 = gosp_set5_temp;
      GospodarzeNazwa = GoscieNazwa_temp;
      GoscieNazwa = GospodarzeNazwa_temp;
}
//****************************************************************************************

void setup()
{
      Serial.begin(57600);
      Serial.print("Laczenie z siecia: ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED)
      {
            delay(500);
            Serial.print(".");
            pixels.begin();
            pixels.setBrightness(90);
      }
      Serial.println("");
      Serial.println("Polaczono z siecią.");
      Serial.println("Adres IP: ");
      Serial.println(WiFi.localIP());
      server.begin();

      while (WiFi.status() != WL_CONNECTED)
      {
            delay(100);
      }
      remoteMe.getVariables()->observeInteger("Goscie_set", onGoscie_setChange);
      remoteMe.getVariables()->observeInteger("Goscie_wynik", onGoscie_wynikChange);
      remoteMe.getVariables()->observeInteger("Gospodarze_set", onGospodarze_setChange);
      remoteMe.getVariables()->observeInteger("Gospodarze_wynik", onGospodarze_wynikChange);
      remoteMe.getVariables()->observeInteger("Set", onSetChange);
      remoteMe.getVariables()->observeInteger("Minuta1", onMinuta1Change);
      remoteMe.getVariables()->observeInteger("Minuta2", onMinuta2Change);
      remoteMe.getVariables()->observeInteger("Sekunda1", onSekunda1Change);
      remoteMe.getVariables()->observeInteger("Sekunda2", onSekunda2Change);
      remoteMe.getVariables()->observeInteger("Goscie_czas", onGoscie_czasChange);
      remoteMe.getVariables()->observeInteger("Gospodarze_czas", onGospodarze_czasChange);
      remoteMe.getVariables()->observeInteger("GoscSet1", onGoscSet1Change);
      remoteMe.getVariables()->observeInteger("GoscSet2", onGoscSet2Change);
      remoteMe.getVariables()->observeInteger("GoscSet3", onGoscSet3Change);
      remoteMe.getVariables()->observeInteger("GoscSet4", onGoscSet4Change);
      remoteMe.getVariables()->observeInteger("GoscSet5", onGoscSet5Change);
      remoteMe.getVariables()->observeInteger("GospSet1", onGospSet1Change);
      remoteMe.getVariables()->observeInteger("GospSet2", onGospSet2Change);
      remoteMe.getVariables()->observeInteger("GospSet3", onGospSet3Change);
      remoteMe.getVariables()->observeInteger("GospSet4", onGospSet4Change);
      remoteMe.getVariables()->observeInteger("GospSet5", onGospSet5Change);
      remoteMe.getVariables()->observeText("Gospodarze_nazwa", onGospodarze_nazwaChange);
      remoteMe.getVariables()->observeText("Goscie_nazwa", onGoscie_nazwaChange);
      remoteMe.getVariables()->observeText("Zagrywajacy", onZagrywajacyChange);
      remoteMe.setConnector(new RemoteMeSocketConnector());
      remoteMe.sendRegisterDeviceMessage(DEVICE_NAME);
}

void loop()
{
      czesc_gry = gosp_set + gosc_set + 1;
      if (czesc_gry > 4)
      {
            gospCzas = 1;
            goscCzas = 1;
      }

      if (gospCzas < 0 || gospCzas > 100)
      {
            gospCzas = 0;
      }
      if (goscCzas < 0 || goscCzas > 100)
      {
            goscCzas = 0;
      }
      if (gosc < 0 || gosc > 100)
      {
            gosc = 0;
      }
      if (gosp < 0 || gosp > 100)
      {
            gosp = 0;
      }
      if (gosc_set < 0 || gosc_set > 100)
      {
            gosc_set = 0;
      }
      if (gosp_set < 0 || gosp_set > 100)
      {
            gosp_set = 0;
      }
      remoteMe.loop();

      if (gosp_set >= 10 && gosp_set <= 19)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 0;
      }
      else if (gosp_set >= 20 && gosp_set <= 29)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 14;
      }
      else if (gosp_set >= 30 && gosp_set <= 39)
      {
            kolorSetGosp1 = 17;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }
      else if (gosp_set >= 40 && gosp_set <= 49)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 69;
      }
      else if (gosp_set >= 50 && gosp_set <= 59)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }
      else if (gosp_set >= 60 && gosp_set <= 69)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 255;
      }
      else if (gosp_set >= 70 && gosp_set <= 79)
      {
            kolorSetGosp1 = 170;
            kolorSetGosp2 = 32;
            kolorSetGosp3 = 235;
      }
      else if (gosp_set >= 80 && gosp_set <= 89)
      {
            kolorSetGosp1 = 20;
            kolorSetGosp2 = 194;
            kolorSetGosp3 = 235;
      }
      else if (gosp_set >= 90 && gosp_set <= 99)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }

      if (gosc_set >= 10 && gosc_set <= 19)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 0;
      }
      else if (gosc_set >= 20 && gosc_set <= 29)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 14;
      }
      else if (gosc_set >= 30 && gosc_set <= 39)
      {
            kolorSetGosp1 = 17;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }
      else if (gosc_set >= 40 && gosc_set <= 49)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 69;
      }
      else if (gosc_set >= 50 && gosc_set <= 59)
      {
            kolorSetGosp1 = 255;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }
      else if (gosc_set >= 60 && gosc_set <= 69)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 255;
            kolorSetGosp3 = 255;
      }
      else if (gosc_set >= 70 && gosc_set <= 79)
      {
            kolorSetGosp1 = 170;
            kolorSetGosp2 = 32;
            kolorSetGosp3 = 235;
      }
      else if (gosc_set >= 80 && gosc_set <= 89)
      {
            kolorSetGosp1 = 20;
            kolorSetGosp2 = 194;
            kolorSetGosp3 = 235;
      }
      else if (gosc_set >= 90 && gosc_set <= 99)
      {
            kolorSetGosp1 = 0;
            kolorSetGosp2 = 0;
            kolorSetGosp3 = 255;
      }
      switch (czesc_gry)
      {
      case 1:
            gosp_set1 = gosp;
            gosc_set1 = gosc;
            break;
      case 2:
            gosp_set2 = gosp;
            gosc_set2 = gosc;
            break;
      case 3:
            gosp_set3 = gosp;
            gosc_set3 = gosc;
            break;
      case 4:
            gosp_set4 = gosp;
            gosc_set4 = gosc;
            break;
      case 5:
            gosp_set5 = gosp;
            gosc_set5 = gosc;
            break;
      default:
            gosc_set1 = 0;
            gosp_set2 = 0;
            gosp_set3 = 0;
            gosp_set4 = 0;
            gosp_set5 = 0;
            gosc_set1 = 0;
            gosc_set2 = 0;
            gosc_set3 = 0;
            gosc_set4 = 0;
            gosc_set5 = 0;
      }
      if (setStan != czesc_gry)
      {
            gosp = 0;
            gosc = 0;
            gospCzas = 2;
            goscCzas = 2;
            if (czesc_gry > 4)
            {
                  gospCzas = 1;
                  goscCzas = 1;
            }
            setStan = czesc_gry;
      }
      if (gospCzas == 2)
      {
            segment50();
      }
      if (gospCzas == 1)
      {
            segment50off();
            pixels.setPixelColor(204, pixels.Color(kolorSetGosp1, kolorSetGosp2, kolorSetGosp3));
      }
      if (gospCzas == 0)
      {
            pixels.setPixelColor(204, pixels.Color(0, 0, 0));
      }

      if (goscCzas == 2)
      {
            segment51();
      }
      if (goscCzas == 1)
      {
            segment51off();
            pixels.setPixelColor(207, pixels.Color(kolorSetGosc1, kolorSetGosc2, kolorSetGosc3));
      }
      if (goscCzas == 0)
      {
            pixels.setPixelColor(207, pixels.Color(0, 0, 0));
      }
      switch (gosp)
      {
      case 0:
            //******************************czyszczenie liczby*************************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //************************************************************************************
            segment8();
            segment9();
            segment10();
            segment12();
            segment13();
            segment14();
            pixels.show();
            break;
      case 1:
            //************************* czyszczenie liczby *******************************
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************
            segment10();
            segment14();
            pixels.show();
            break;
      case 2:
            //************************* czyszczenie liczby *******************************
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
            segment9();
            segment10();
            segment11();
            segment12();
            segment13();
            pixels.show();
            break;
      case 3:
            //************************* czyszczenie liczby *******************************
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
            segment9();
            segment10();
            segment11();
            segment14();
            segment13();
            pixels.show();
            break;
      case 4:
            //************************* czyszczenie liczby *******************************
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
            segment8();
            segment11();
            segment10();
            segment14();
            pixels.show();
            break;
      case 5:
            //************************* czyszczenie liczby *******************************
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
            segment9();
            segment8();
            segment11();
            segment14();
            segment13();
            pixels.show();
            break;
      case 6:
            //************************* czyszczenie liczby *******************************
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
            segment9();
            segment8();
            segment12();
            segment13();
            segment14();
            segment11();
            pixels.show();
            break;
      case 7:
            //************************* czyszczenie liczby *******************************
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
            segment9();
            segment10();
            segment14();
            pixels.show();
            break;
      case 8:
            //************************* czyszczenie liczby *******************************
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
            segment8();
            segment9();
            segment10();
            segment11();
            segment13();
            segment14();
            pixels.show();
            break;
      case 10:
            //************************* czyszczenie liczby *******************************
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
            //****************10************************
            segment3();
            segment7();
            //******************************************
            //****************0*************************
            segment8();
            segment9();
            segment10();
            segment12();
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 11:
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment10off();
            segment14off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();

            segment10off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 21:
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();

            segment10off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 31:
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();

            segment10off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 41:
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment3off();
            segment4off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();

            segment10off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 51:
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment4off();
            segment7off();
            segment6off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 61:
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment2off();
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment1off();
            segment5off();
            segment6off();
            segment7off();
            segment4off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 71:
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment2off();
            segment3off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 81:
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();

            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment5off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            pixels.show();
            break;
      case 91:
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment12off();
            segment13off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment10off();
            segment14off();

            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();

            segment8off();
            segment11off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment11off();
            segment10off();
            segment14off();

            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment11off();
            segment14off();
            segment13off();

            segment9off();
            segment10off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment8off();
            segment12off();
            segment13off();
            segment14off();
            segment11off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment9off();
            segment10off();
            segment14off();

            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment1off();
            segment2off();
            segment3off();
            segment4off();
            segment6off();
            segment7off();
            segment8off();
            segment9off();
            segment10off();
            segment11off();
            segment12off();
            segment13off();
            segment14off();
            //****************************************************************************();
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
            segment13();
            segment14();
            //******************************************
            gosp = 0;
            break;
      }

      switch (gosc)
      {
      case 0:
            //*********************************czyszczenie liczby**********************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //*************************************************************************************
            segment22();
            segment23();
            segment24();
            segment26();
            segment27();
            segment28();
            pixels.show();
            break;
      case 1:
            //************************* czyszczenie liczby *******************************
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
            segment24();
            segment28();
            pixels.show();
            break;
      case 2:
            //************************* czyszczenie liczby *******************************
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            segment23();
            segment24();
            segment25();
            segment26();
            segment27();
            pixels.show();
            break;
      case 3:
            //************************* czyszczenie liczby *******************************
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
            segment23();
            segment24();
            segment25();
            segment28();
            segment27();
            pixels.show();
            break;
      case 4:
            //************************* czyszczenie liczby *******************************
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            segment22();
            segment25();
            segment24();
            segment28();
            pixels.show();
            break;
      case 5:
            //************************* czyszczenie liczby *******************************
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
            segment23();
            segment22();
            segment25();
            segment28();
            segment27();
            pixels.show();
            break;
      case 6:
            //************************* czyszczenie liczby *******************************
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
            segment23();
            segment22();
            segment26();
            segment27();
            segment28();
            segment25();
            pixels.show();
            break;
      case 7:
            //************************* czyszczenie liczby *******************************
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
            segment23();
            segment24();
            segment28();
            pixels.show();
            break;
      case 8:
            //************************* czyszczenie liczby *******************************
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment17off();
            segment21off();
            //****************************************************************************();
            segment22();
            segment23();
            segment24();
            segment25();
            segment27();
            segment28();
            pixels.show();
            break;
      case 10:
            //************************* czyszczenie liczby *******************************
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************10************************
            segment17();
            segment21();
            //******************************************
            //****************0*************************
            segment22();
            segment23();
            segment24();
            segment26();
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 11:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
            //****************10************************
            segment17();
            segment21();
            //******************************************

            //***************1**************************
            segment24();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 12:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            //****************10************************
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
      case 13:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
            //****************10************************
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
      case 14:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            //****************10************************
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
      case 15:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
            //****************10************************
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
      case 16:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
            //****************10************************
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
      case 17:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************10************************
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
      case 18:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************10************************
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
      case 19:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            //****************************************************************************();
            //****************10************************
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
      case 20:
            //************************* czyszczenie liczby *******************************
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 21:
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 31:
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment15off();
            segment17off();
            segment18off();
            segment21off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 41:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment17off();
            segment18off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 51:
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment18off();
            segment21off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 61:
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            segment16off();
            segment17off();
            segment21off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment15off();
            segment19off();
            segment20off();
            segment21off();
            segment18off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 71:
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment16off();
            segment17off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 81:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();

            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment19off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
            segment27();
            segment28();
            //******************************************
            pixels.show();
            break;
      case 91:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment21off();
            segment22off();
            segment23off();
            segment24off();
            segment26off();
            segment27off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 92:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment24off();
            segment28off();

            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 93:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();

            segment22off();
            segment25off();
            segment24off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 94:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 95:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment22off();
            segment25off();
            segment24off();
            segment28off();

            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 96:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment22off();
            segment25off();
            segment28off();
            segment27off();

            segment23off();
            segment24off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 97:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment22off();
            segment26off();
            segment27off();
            segment28off();
            segment25off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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
      case 98:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment28off();

            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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

      case 99:
            //************************* czyszczenie liczby *******************************
            segment15off();
            segment16off();
            segment17off();
            segment18off();
            segment20off();
            segment22off();
            segment23off();
            segment24off();
            segment25off();
            segment26off();
            segment27off();
            segment28off();
            //****************************************************************************();
            //****************90************************
            segment15();
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

      default:
            // pixels.clear(); // Set all pixel colors to 'off'
            //****************0*************************
            segment22();
            segment23();
            segment24();
            segment26();
            segment27();
            segment28();
            //******************************************
            gosc = 0;
            break;
      }
      switch (gosp_set)
      {
      case 0:
            //***************************************************************************
            segment43off();
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();
            segment49off();
            //***************************************************************************
            segment44();
            segment45();
            segment43();
            segment47();
            segment48();
            segment49();
            pixels.show();
            break;
      case 1:
            //***************************************************************************
            segment44off();
            segment45off();
            segment43off();
            segment47off();
            segment48off();
            segment49off();
            segment46off();
            //***************************************************************************
            segment43();
            segment47();
            pixels.show();
            break;
      case 2:
            //************************* czyszczenie liczby *******************************
            segment43off();
            segment47off();
            segment44off();
            segment43off();
            segment46off();
            segment47off();
            segment48off();
            //****************************************************************************();
            segment44();
            segment43();
            segment46();
            segment49();
            segment48();
            pixels.show();
            break;
      case 3:
            //************************* czyszczenie liczby *******************************
            segment44off();
            segment43off();
            segment46off();
            segment47off();
            segment48off();
            segment49off();
            segment45off();
            segment46off();
            segment43off();
            segment47off();
            //****************************************************************************();
            segment44();
            segment43();
            segment46();
            segment47();
            segment48();
            pixels.show();
            break;
      case 4:
            //************************* czyszczenie liczby *******************************
            segment44off();
            segment43off();
            segment46off();
            segment47off();
            segment48off();
            segment49off();
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();
            //****************************************************************************();
            segment45();
            segment46();
            segment43();
            segment47();
            pixels.show();
            break;
      case 5:
            //************************* czyszczenie liczby *******************************
            segment45off();
            segment46off();
            segment43off();
            segment47off();
            segment44off();
            segment45off();
            segment49off();
            segment48off();
            segment47off();
            segment46off();
            //****************************************************************************();
            segment44();
            segment45();
            segment46();
            segment47();
            segment48();
            pixels.show();
            break;
      case 6:
            //************************* czyszczenie liczby *******************************
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();

            segment44off();
            segment43off();
            segment47off();
            //****************************************************************************();
            segment44();
            segment45();
            segment49();
            segment48();
            segment47();
            segment46();
            pixels.show();
            break;
      case 7:
            //************************* czyszczenie liczby *******************************
            segment44off();
            segment45off();
            segment49off();
            segment48off();
            segment47off();
            segment46off();

            segment43off();
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();
            segment49off();
            //****************************************************************************();
            segment44();
            segment43();
            segment47();
            pixels.show();
            break;
      case 8:
            //************************* czyszczenie liczby *******************************
            segment44off();
            segment43off();
            segment47off();

            segment43off();
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment43off();
            segment44off();
            segment45off();
            segment46off();
            segment47off();
            segment48off();
            segment49off();
            //****************************************************************************();
            segment43();
            segment44();
            segment45();
            segment46();
            segment47();
            segment48();
            pixels.show();
            break;

      default:
            // pixels.clear(); // Set all pixel colors to 'off'
            gosp_set = 0;
            break;
      }
      switch (gosc_set)
      {
      case 0:
            //****************************czysczenie liczby*************************************
            segment29off();
            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            segment35off();
            //**********************************************************************************
            segment29();
            segment30();
            segment31();
            segment33();
            segment34();
            segment35();
            pixels.show();
            break;
      case 1:
            // *****************************czyszczenie liczby**********************************
            segment29off();
            segment30off();
            segment31off();
            segment33off();
            segment34off();
            segment35off();

            segment30off();
            segment29off();
            segment32off();
            segment35off();
            segment34off();
            //******************************************************************
            segment29();
            segment33();
            pixels.show();
            break;
      case 2:
            //************************* czyszczenie liczby *******************************
            segment29off();
            segment33off();

            segment30off();
            segment29off();
            segment32off();
            segment33off();
            segment34off();
            //****************************************************************************();
            segment30();
            segment29();
            segment32();
            segment35();
            segment34();
            pixels.show();
            break;
      case 3:
            //************************* czyszczenie liczby *******************************
            segment30off();
            segment29off();
            segment32off();
            segment35off();
            segment34off();

            segment31off();
            segment32off();
            segment29off();
            segment33off();
            //****************************************************************************();
            segment30();
            segment29();
            segment32();
            segment33();
            segment34();
            pixels.show();
            break;
      case 4:
            //************************* czyszczenie liczby *******************************
            segment30off();
            segment29off();
            segment32off();
            segment33off();
            segment34off();

            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            //****************************************************************************();
            segment31();
            segment32();
            segment29();
            segment33();
            pixels.show();
            break;
      case 5:
            //************************* czyszczenie liczby *******************************
            segment31off();
            segment32off();
            segment29off();
            segment33off();
            segment30off();
            segment31off();
            segment32off();
            segment35off();
            segment34off();
            segment33off();
            //****************************************************************************();
            segment30();
            segment31();
            segment32();
            segment33();
            segment34();
            pixels.show();
            break;
      case 6:
            //************************* czyszczenie liczby *******************************
            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            segment30off();
            segment29off();
            segment33off();
            //****************************************************************************();
            segment30();
            segment31();
            segment32();
            segment35();
            segment34();
            segment33();
            pixels.show();
            break;
      case 7:
            //************************* czyszczenie liczby *******************************
            segment30off();
            segment31off();
            segment32off();
            segment35off();
            segment34off();
            segment33off();

            segment29off();
            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            segment35off();
            //****************************************************************************();
            segment30();
            segment29();
            segment33();
            pixels.show();
            break;
      case 8:
            //************************* czyszczenie liczby *******************************
            segment30off();
            segment29off();
            segment33off();
            segment29off();
            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment29off();
            segment30off();
            segment31off();
            segment32off();
            segment33off();
            segment34off();
            segment35off();
            //****************************************************************************();
            segment29();
            segment30();
            segment31();
            segment32();
            segment33();
            segment34();
            pixels.show();
            break;
      default:
            // pixels.clear(); // Set all pixel colors to 'off'
            gosc_set = 0;
            break;
      }
      switch (czesc_gry)
      {
      case 0:
            //**************************************czyszczenie liczby*******************
            segment36off();
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            segment42off();
            //***************************************************************************
            segment36();
            segment37();
            segment38();
            segment42();
            segment41();
            segment40();
            pixels.show();
            break;
      case 1:
            //******************************czyszczenie liczby*********************
            segment36off();
            segment37off();
            segment38off();
            segment42off();
            segment41off();
            segment40off();

            segment37off();
            segment36off();
            segment39off();
            segment42off();
            segment41off();
            //*****************************************************************************
            segment36();
            segment40();
            pixels.show();
            break;
      case 2:
            //************************* czyszczenie liczby *******************************
            segment36off();
            segment40off();

            segment37off();
            segment36off();
            segment39off();
            segment40off();
            segment41off();
            //****************************************************************************();
            segment37();
            segment36();
            segment39();
            segment42();
            segment41();
            pixels.show();
            break;
      case 3:
            //************************* czyszczenie liczby *******************************
            segment37off();
            segment36off();
            segment39off();
            segment42off();
            segment41off();

            segment38off();
            segment39off();
            segment36off();
            segment40off();
            //****************************************************************************();
            segment37();
            segment36();
            segment39();
            segment40();
            segment41();
            pixels.show();
            break;
      case 4:
            //************************* czyszczenie liczby *******************************
            segment37off();
            segment36off();
            segment39off();
            segment40off();
            segment41off();

            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            //****************************************************************************();
            segment38();
            segment39();
            segment36();
            segment40();
            pixels.show();
            break;
      case 5:
            //************************* czyszczenie liczby *******************************
            segment38off();
            segment39off();
            segment36off();
            segment40off();

            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            segment42off();
            //****************************************************************************();
            segment37();
            segment38();
            segment39();
            segment40();
            segment41();
            pixels.show();
            break;
      case 6:
            //************************* czyszczenie liczby *******************************
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();

            segment37off();
            segment36off();
            segment40off();
            //****************************************************************************();
            segment37();
            segment38();
            segment39();
            segment40();
            segment41();
            segment42();
            pixels.show();
            break;
      case 7:
            //************************* czyszczenie liczby *******************************
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            segment42off();

            segment36off();
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            segment42off();
            //****************************************************************************();
            segment37();
            segment36();
            segment40();
            pixels.show();
            break;
      case 8:
            //************************* czyszczenie liczby *******************************
            segment37off();
            segment36off();
            segment40off();

            segment36off();
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            //****************************************************************************();
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
            //************************* czyszczenie liczby *******************************
            segment36off();
            segment37off();
            segment38off();
            segment39off();
            segment40off();
            segment41off();
            segment42off();
            //****************************************************************************();
            segment36();
            segment37();
            segment38();
            segment39();
            segment40();
            segment41();
            pixels.show();
            break;
      default:
            czesc_gry = 0;
            break;
      }
      WiFiClient client = server.available();
      if (client)
      {

            String currentLine = "";
            currentTime = millis();
            previousTime = currentTime;
            while (client.connected() && currentTime - previousTime <= timeoutTime)
            {
                  currentTime = millis();
                  if (client.available())
                  {
                        char c = client.read();

                        header += c;

                        if (c == '\n')
                        {
                              if (currentLine.length() == 0)
                              {

                                    client.println("HTTP/1.1 200 OK");
                                    client.println("Content-type:text/html");
                                    client.println("Connection: close");
                                    client.println();

                                    if (header.indexOf("GET /gosp+/on") >= 0)
                                    {

                                          gospPlState = "on";
                                    }
                                    else if (header.indexOf("GET /gosp+/off") >= 0)
                                    {
                                          Serial.println("Dodano punkt gospodarzom");
                                          gospPlState = "off";
                                    }
                                    else if (header.indexOf("GET /gosp-/on") >= 0)
                                    {

                                          gospMiState = "on";
                                    }
                                    else if (header.indexOf("GET /gosp-/off") >= 0)
                                    {
                                          Serial.println("Odjeto punkt gospodarzom");
                                          gospMiState = "off";
                                    }
                                    else if (header.indexOf("GET /gosp_set+/on") >= 0)
                                    {

                                          gospSetPlState = "on";
                                    }
                                    else if (header.indexOf("GET /gosp_set+/off") >= 0)
                                    {
                                          Serial.println("Dodano set gospodarzom");
                                          gospSetPlState = "off";
                                    }
                                    else if (header.indexOf("GET /gosp_set-/on") >= 0)
                                    {

                                          gospSetMiState = "on";
                                    }
                                    else if (header.indexOf("GET /gosp_set-/off") >= 0)
                                    {
                                          Serial.println("Odjeto set gospodarzom");
                                          gospSetMiState = "off";
                                    }
                                    else if (header.indexOf("GET /punktyReset/on") >= 0)
                                    {

                                          punktyReset = "on";
                                    }
                                    else if (header.indexOf("GET /punktyReset/off") >= 0)
                                    {
                                          Serial.println("Nastapil reset");
                                          punktyReset = "off";
                                    }
                                    else if (header.indexOf("GET /gospodarzeCzas/on") >= 0)
                                    {

                                          gospodarzeCzas = "on";
                                    }
                                    else if (header.indexOf("GET /gospodarzeCzas/off") >= 0)
                                    {
                                          Serial.println("Czas dla Gospodarzy");
                                          gospodarzeCzas = "off";
                                    }
                                    else if (header.indexOf("GET /goscieCzas/on") >= 0)
                                    {

                                          goscieCzas = "on";
                                    }
                                    else if (header.indexOf("GET /goscieCzas/off") >= 0)
                                    {
                                          Serial.println("Czas dla Gosci");
                                          goscieCzas = "off";
                                    }
                                    else if (header.indexOf("GET /gosc+/on") >= 0)
                                    {

                                          goscPlState = "on";
                                    }
                                    else if (header.indexOf("GET /gosc+/off") >= 0)
                                    {
                                          Serial.println("Dodano punkt Gosciom");
                                          goscPlState = "off";
                                    }
                                    else if (header.indexOf("GET /gosc-/on") >= 0)
                                    {

                                          goscMiState = "on";
                                    }
                                    else if (header.indexOf("GET /gosc-/off") >= 0)
                                    {
                                          Serial.println("Odjeto punkt Gosciom");
                                          goscMiState = "off";
                                    }
                                    else if (header.indexOf("GET /gosc_set+/on") >= 0)
                                    {

                                          goscSetPlState = "on";
                                    }
                                    else if (header.indexOf("GET /gosc_set+/off") >= 0)
                                    {
                                          Serial.println("Dodano set gosciom");
                                          goscSetPlState = "off";
                                    }
                                    else if (header.indexOf("GET /gosc_set-/on") >= 0)
                                    {

                                          goscSetMiState = "on";
                                    }
                                    else if (header.indexOf("GET /gosc_set-/off") >= 0)
                                    {
                                          Serial.println("Odjeto set gosciom");
                                          goscSetMiState = "off";
                                    }
                                    else if (header.indexOf("GET /startCzas/off") >= 0)
                                    {
                                          Serial.println("Start pomiaru czasu");
                                          startCzas = "off";
                                    }
                                    else if (header.indexOf("GET /startCzas/on") >= 0)
                                    {
                                          Serial.println("Zatrzymanie startu pomiaru czasu");
                                          startCzas = "on";
                                    }
                                    else if (header.indexOf("GET /stopCzas/off") >= 0)
                                    {
                                          Serial.println("Zatrzymanie czasu");
                                          stopCzas = "off";
                                    }
                                    else if (header.indexOf("GET /stopCzas/on") >= 0)
                                    {
                                          Serial.println("Zatwierdzenie zatrzymania");
                                          stopCzas = "on";
                                    }
                                    else if (header.indexOf("GET /pauzaCzas/off") >= 0)
                                    {
                                          Serial.println("Pauza");
                                          pauzaCzas = "off";
                                    }
                                    else if (header.indexOf("GET /pauzaCzas/on") >= 0)
                                    {
                                          Serial.println("Potwierdzenie pauzy");
                                          pauzaCzas = "on";
                                    }
                                    else if (header.indexOf("GET /zamienStrony/off") >= 0)
                                    {
                                          Serial.println("Zamiana stron");
                                          zamienStrony = "off";
                                    }
                                    else if (header.indexOf("GET /zamienStrony/on") >= 0)
                                    {
                                          Serial.println("Potwierdzenie zamiany stron");
                                          zamienStrony = "on";
                                    }

                                    client.println("<!DOCTYPE html><html>");
                                    client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                                    //    client.println("<head> <meta http-equiv=\"refresh\" content=\"30\"></head>");
                                    //       client.println("<meta charset=\"UTF-8\"></meta>");
                                    client.println("<link rel=\"icon\" href=\"data:,\">");
                                    client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; background-color: aqua; color:black;}");
                                    client.println(".button_gosp {");
                                    client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; background-color:red; color:white;}");
                                    client.println(".button_gosc {");
                                    client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; background-color:green; color:white;}");
                                    client.println(".button_obsluga {");
                                    client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer; background-color:blue; color:white;}");
                                    client.println(".gospodarze {margin:2px;float:left;}");
                                    client.println(".button2 {background-color: #77878A;}");
                                    client.println(".czysciciel {clear:both;}</style></head>");

                                    client.println("<body><center><h1>Panel sterowania </h1></center>");

                                    client.println("<form method=get>");
                                    client.println("<input type=text name='gospodarzeNazwa' placeholder='Gospodarze' value=''>");
                                    client.println("<input type=text name='goscieNazwa_' placeholder='Goscie' value=''>");
                                    client.println("<input type=submit name='submitX' value='Zatwierdz Druzyny' onclick=Gospodarze();>");
                                    int f = header.length();
                                    if (f > 570 and f < 890)
                                    {
                                          int pos1 = header.indexOf('?');
                                          int pos2 = header.indexOf('&');
                                          int pos3 = header.indexOf('_');
                                          int pos4 = header.indexOf('X');
                                          GospodarzeNazwa = header.substring(pos1 + 17, pos2);
                                          GoscieNazwa = header.substring(pos3 + 2, pos4 - 7);
                                          GospodarzeNazwa.replace("+", " ");
                                          GoscieNazwa.replace("+", " ");
                                    }
                                    else
                                    {
                                          int pos1 = header.indexOf('?');
                                          int pos2 = header.indexOf('&');
                                          int pos3 = header.indexOf('_');
                                          int pos4 = header.indexOf('X');
                                    }
                                    client.println("</form>");

                                    client.println("<hr>");
                                    client.println("<p>Gospodarze</p>");

                                    if (gospPlState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp+/on\"><button class=\"button_gosp\">Punkt+</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp+/off\"><button class=\"button_gosp button2\">Zatwierdz</button></a></p>");
                                          gosp++;
                                          Zagrywka = GospodarzeNazwa;
                                          serwGosp();
                                          serwGoscoff();
                                    }

                                    if (gospMiState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp-/on\"><button class=\"button_gosp\">Punkt-</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp-/off\"><button class=\"button_gosp button2\">Zatwierdz</button></a></p>");
                                          gosp--;
                                    }

                                    if (gospSetPlState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp_set+/on\"><button class=\"button_gosp\">Set+</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp_set+/off\"><button class=\"button_gosp button2\">Zatwierdz</button></a></p>");
                                          gosp_set++;
                                    }

                                    if (gospSetMiState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp_set-/on\"><button class=\"button_gosp\">Set-</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosp_set-/off\"><button class=\"button_gosp button2\">Zatwierdz</button></a></p>");
                                          gosp_set--;
                                    }
                                    client.println("<p class=\"czysciciel\"></p>");
                                    client.println("<hr>");
                                    client.println("<p>Obsluga spotkania</p>");
                                    if (punktyReset == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/punktyReset/on\"><button class=\"button_obsluga\">Reset</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/punktyReset/off\"><button class=\"button_obsluga button2\">Zatwierdz</button></a></p>");
                                          pixels.clear();
                                          gosp = 0;
                                          gosc = 0;
                                          gosp_set = 0;
                                          gosc_set = 0;
                                          gospCzas = 2;
                                          goscCzas = 2;
                                          setStan = 1;
                                          gosp_set1 = 0;
                                          gosp_set2 = 0;
                                          gosp_set3 = 0;
                                          gosp_set4 = 0;
                                          gosp_set5 = 0;
                                          gosc_set1 = 0;
                                          gosc_set2 = 0;
                                          gosc_set3 = 0;
                                          gosc_set4 = 0;
                                          gosc_set5 = 0;
                                          GospodarzeNazwa = "Gospodarze";
                                          GoscieNazwa = "Goscie";
                                          pixels.show();
                                    }
                                    if (gospodarzeCzas == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gospodarzeCzas/on\"><button class=\"button_gosp\">Gosp - Czas</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gospodarzeCzas/off\"><button class=\"button_gosp button2\">Zatwierdz</button></a></p>");
                                          gospCzas--;
                                    }
                                    if (goscieCzas == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/goscieCzas/on\"><button class=\"button_gosc\">Gosc - Czas</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/goscieCzas/off\"><button class=\"button_gosc button2\">Zatwierdz</button></a></p>");
                                          goscCzas--;
                                    }
                                    if (zamienStrony == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/zamienStrony/on\"><button class=\"button_obsluga\">Zamien Strony</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/zamienStrony/off\"><button class=\"button_obsluga button2\">Zatwierdz</button></a></p>");
                                          ZamienStrony();
                                    }

                                    client.println("<p class=\"czysciciel\"></p>");
                                    client.println("<hr>");
                                    client.println("<p>Goscie</p>");

                                    if (goscPlState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc+/on\"><button class=\"button_gosc\">Punkt+</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc+/off\"><button class=\"button_gosc button2\">Zatwierdz</button></a></p>");
                                          gosc++;
                                          Zagrywka = GoscieNazwa;
                                          serwGospoff();
                                          serwGosc();
                                    }

                                    if (goscMiState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc-/on\"><button class=\"button_gosc\">Punkt-</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc-/off\"><button class=\"button_gosc button2\">Zatwierdz</button></a></p>");
                                          gosc--;
                                    }

                                    if (goscSetPlState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc_set+/on\"><button class=\"button_gosc\">Set+</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc_set+/off\"><button class=\"button_gosc button2\">Zatwierdz</button></a></p>");
                                          gosc_set++;
                                    }
                                    // If the output5State is off, it displays the ON button
                                    if (goscSetMiState == "off")
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc_set-/on\"><button class=\"button_gosc\">Set-</button></a></p>");
                                    }
                                    else
                                    {
                                          client.println("<p class=\"gospodarze\"><a href=\"/gosc_set-/off\"><button class=\"button_gosc button2\">Zatwierdz</button></a></p>");
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
                                    client.println("<p>Gospodarze</p>");
                                    client.println(GospodarzeNazwa);
                                    client.println("<p>Goscie</p>");
                                    client.println(GoscieNazwa);
                                    client.println("<p>Zagrywka</p>");
                                    client.println(Zagrywka);
                                    client.println("</body></html>");

                                    client.println();
                                    break;
                              }
                              else
                              { 
                                    currentLine = "";
                              }
                        }
                        else if (c != '\r')
                        {                       
                              currentLine += c; 
                        }
                  }
            }
            header = "";
            client.stop();
            Serial.println("");
      }
      static long time = millis();
      if (time + 5000 < millis()) // 700
      {                           
            time = millis();
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
            setGospSet1(gosp_set1);
            setGospSet2(gosp_set2);
            setGospSet3(gosp_set3);
            setGospSet4(gosp_set4);
            setGospSet5(gosp_set5);
            setGoscSet1(gosc_set1);
            setGoscSet2(gosc_set2);
            setGoscSet3(gosc_set3);
            setGoscSet4(gosc_set4);
            setGoscSet5(gosc_set5);
            setGospodarze_nazwa(GospodarzeNazwa);
            setGoscie_nazwa(GoscieNazwa);
            setZagrywajacy(Zagrywka);
      }
}
