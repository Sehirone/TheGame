#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <SFML/Audio.hpp>
#define sound(x)    if(sound == 49) soundeffect(x);
using namespace std;

void sklep(void);               // Sklep, po walce/ucieczce
void akt_poziomk(void);         // Aktualny poziom, po wypisaniu +1
void klawisz(void);             // Aby przejsc dalej wcisnij dowolny klawisz + czyszczenie ekranu
void potwor(void);              // Losowanie potwora
void nagroda(void);             // Nagroda po zabiciu potwora/ucieczce
void klasy(void);               // Wybor klasy
void barbarzynca(void);         // Walka, jezeli klasa to barbarzynca
void lowca(void);               // Walka, jezeli klasa to lowca
void mag(void);                 // Walka, jezeli klasa to mag
void wrog(void);                // Atak wroga
void towarzysz(void);           // Atak towarzysza
void useitem(void);             // Uzycie przedmiotu
void itemdrop(void);            // Losowanie przedmiotu
void soundeffect(int ktory);    // Odtwarzanie düwieku

string imie;                      // Imie twoje
string eimie;                     // Imie wroga
string simie;                     // Imie brata/siostry
string item;                      // Nazwa przedmiotu
short int itemnr;                 // Nr. przedmiotu
short int akt_poziom;             // Aktualny poziom
short int ehp, earm, eatk;        // Zycie wroga, Zbroja wroga, Atak wroga
short int monster_type;           // 1.Beast 2.Undead 3.Humanoid
short int hp, mp, rage, energy;   // Zycie, Mana, Zlosc, Energia
short int arm, atk;               // Zbroja, Atak
short int dmg;                    // Zadane obrazenia
double zloto;                     // Zloto
short int ucieczka;               // 1. Ucieczka udana 0. Ucieczka nieudana
short int klasa;                  // 1. Barbarzynca 2. lowca 3. Mag
short int atk_type;               // 1. Wrecz 2. Na odleglosc
short int companion;              // 2. Dwie Walki 1. Jedna Walka 0. Brak
char potwierdzenie;               // Pytanie o ponowna gre
short int sound;                  // 1. Wlaczony 2. Wylaczony
sf::Music music;                  // Odtwarzanie tla
sf::Sound short_music;            // Odtwarzanie efektorw

//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
inline void statystyki(void)
{
    cout << "Obecnie posiadasz " << hp << " zycia, " << atk << " ataku, " << arm << " pkt. pancerza oraz ";
    if(klasa == 49) cout << rage << " pkt. zlosci.\n";
    else if(klasa == 50) cout << energy << " pkt. energii.\n";
    else if(klasa == 51) cout << mp << " pkt. magii.\n";
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
inline void randdmg(void)
{
    dmg = rand() % dmg + (int)(dmg/2 + 0.5);
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
int main()
{
    srand (time(NULL));
    music.setVolume(40);
    soundset:
    cout << "Dzwiek:\n[1] Wlacz\n[2] Wylacz\n";
    sound = getch();
    system("cls");
    if(sound == 49 or sound == 50);
    else goto soundset;
    do
    {
    sound(2)
    ucieczka = 0;
    akt_poziom = 1;
    zloto = 0;
    companion = 0;
    item = "Brak";
    itemnr = 0;
    klasy();
    if(klasa == 49) cout << "Witaj mlody barbarzynco.\nPrzypomnij mi, jak sie nazywasz?\n";
    else if(klasa == 50) cout << "Witaj mlody lowco. \nPrzypomnij mi, jak sie nazywasz?\n";
    else if(klasa == 51) cout << "Witaj mlody magu. \nPrzypomnij mi, jak sie nazywasz?\n";
    cin  >> imie;
    system("cls");
    cout << "Ahhh... No tak! " << imie << "...\n";
    cout << "Czy nie miales czasem aby siostry lub brata?\nPrzypomnisz mi jak mial/miala na imie?\n";
    cin  >> simie;
    system("cls");
    cout << "Ahhh... No tak... " << simie << "... Cos slabo ostatnio z moja pamiecia...\n"
         << "No ale nic..."
         << "\nNadeszla twoja pora, musisz uratowac swiat!"
         << "\nWybacz, ze nie moge dac ci wiecej, ale prosze, wez te pare zlotych monet.";
    klawisz();
    cout << "Otrzymujesz 5 szt. zlota!";
    klawisz();
    zloto = zloto + 5;
    do
    {
    if(akt_poziom == 1) {sound(1)}
    else if(akt_poziom == 6) {sound(3)}
    else if(akt_poziom == 11) {sound(4)}
    else if(akt_poziom == 16) {sound(5)}
    akt_poziomk();
    potwor();
    cout << "Zauwazasz ze cos zbliza sie w twoim kierunku... To " << eimie << "!";
    klawisz();
    if(klasa == 49) barbarzynca();
    else if(klasa == 50) lowca();
    else if(klasa == 51) mag();
    if(akt_poziom == 15 and ucieczka == 1)
    {
        sound(6)
        cout << "Nie mozna uciec przed swoim przeznaczeniem!" << endl
             << eimie << " dogania cie i morduje z zimna krwia...";
             hp = 0;
             klawisz();
    }
    if(hp <= 0)
    {
        sound(6)
        cout << "Polegles, teraz swiat czeka zaglada. No chyba ze sprobujesz jeszcze raz :)\n\n"
             << "Czy chcesz ponownie rozpoczac przygode? [T/N] ";
        cin  >> potwierdzenie;
        if(potwierdzenie == 'T' or potwierdzenie == 't') break;
        else return 0;
    }
    if(akt_poziom == 20)
    {
        if(ucieczka == 0)
        {
            cout << "Udaje ci sie pokonac krula kucykolandii!\nPrzechodzisz obok jego ciala, zabierasz mu berlo i siadasz na jego tronie!\nZostajesz krulem wszelkich kucykow!\n\n"
                 << "Czy chcesz zagrac jeszcze raz?[T/N]";
            cin  >> potwierdzenie;
            if(potwierdzenie == 'T' or potwierdzenie == 't') break;
            else return 0;
        }
        if(ucieczka == 1)
        {
            sound(6)
            cout << "Wykradasz krulowi berlo jednak ten cie dogania i zjada...\n\n"
                 << "Czy chcesz zagrac jeszcze raz?[T/N]";
            cin  >> potwierdzenie;
            if(potwierdzenie == 'T' or potwierdzenie == 't') break;
            else return 0;
        }
    }
    nagroda();
    if(akt_poziom == 15 and ucieczka == 0)
    {
        cout << "Gratulacje! \nTeraz kiedy " << eimie << " jest martwy swiat jest w koncu bezpieczny.\n"
             << "Widzisz jednak teleport, a ze jestes kozakiem to wpierdalasz sie w niego bez zastanowienia...\n"
             << "Teleport przenosi cie do magicznej krainy!";
        klawisz();
    }
    companion--;
    ucieczka = 0;
    if(sound == 49) music.pause();
    sklep();
    if(sound == 49) music.play();
    akt_poziom++;
    }
    while(hp > 0);
    system("cls");
    }
    while(potwierdzenie == 'T' or potwierdzenie == 't');
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void sklep(void)
{
    short int rodzaj_kupca = rand() % 3+1;
    short int zakup;
sklepo:
    switch(rodzaj_kupca)
    {
        case 1:
            statystyki();
            cout << "\nSpotykasz na swej drodze kowala, oferuje Ci mozliwosc ulepszenia broni w zamian za niewielka oplate:\n"
                 << "[1] +1 ataku - 4 szt. zlota\n"
                 << "[2] +3 ataku - 9 szt. zlota\n"
                 << "[3] +5 ataku - 13 szt. zlota\n"
                 << "[4] +7 ataku - 18 szt. zlota\n"
                 << "[5] +14 ataku - 40 szt. zlota\n"
                 << "[6] Bywaj!\n"
                 << "\nIlosc posiadanego przez ciebie zlota: " << zloto << endl;
            sound(22);
            zakup = getch();
            system("cls");
                 switch(zakup)
                 {
                    case 49:
                        if(zloto >= 4)
                        {
                        cout << "Twoj atak wzrosl o 1 pkt.!";
                        zloto = zloto - 4;
                        atk = atk + 1;
                        sound(21);
                        }
                        else {cout << "Kowal zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 50:
                        if(zloto >= 9)
                        {
                        cout << "Twoj atak wzrosl o 3 pkt.!";
                        zloto = zloto - 9;
                        atk = atk + 3;
                        sound(21);
                        }
                        else {cout << "Kowal zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 51:
                        if(zloto >= 13)
                        {
                        cout << "Twoj atak wzrosl o 5 pkt.!";
                        zloto = zloto - 13;
                        atk = atk + 5;
                        sound(21);
                        }
                        else {cout << "Kowal zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 52:
                        if(zloto >= 18)
                        {
                        cout << "Twoj atak wzrosl o 7 pkt.!";
                        zloto = zloto - 18;
                        atk = atk + 7;
                        sound(21);
                        }
                        else {cout << "Kowal zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 53:
                        if(zloto >= 40)
                        {
                        cout << "Twoj atak wzrosl o 14 pkt.!";
                        zloto = zloto - 40;
                        atk = atk + 14;
                        sound(21);
                        }
                        else {cout << "Kowal zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 54:
                        cout << "Bog z toba wedrowcze!";
                        sound(21);
                        break;
                    default:
                        goto sklepo;
                 }
                 break;
        case 2:
            statystyki();
            cout << "\nSpotykasz na swej drodze zbrojmistrza, oferuje Ci mozliwosc ulepszenia pancerza w zamian za niewielka oplate:\n"
                 << "[1] +1 pancerza - 3 szt. zlota\n"
                 << "[2] +3 pancerza - 7 szt. zlota\n"
                 << "[3] +5 pancerza - 10 szt. zlota\n"
                 << "[4] +7 pancerza - 14 szt. zlota\n"
                 << "[5] +14 pancerza - 30 szt. zlota\n"
                 << "[6] Bywaj!\n"
                 << "\nIlosc posiadanego przez ciebie zlota: " << zloto << endl;
            sound(23);
            zakup = getch();
            system("cls");
                 switch(zakup)
                 {
                    case 49:
                        if(zloto >= 3)
                        {
                        cout << "Twoj pacnerz wzrosl o 1 pkt.!";
                        arm = arm + 1;
                        zloto = zloto - 3;
                        sound(21);
                        }
                        else {cout << "Zbrojmistrz zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 50:
                        if(zloto >= 7)
                        {
                        cout << "Twoj pacnerz wzrosl o 3 pkt.!";
                        arm = arm + 3;
                        zloto = zloto - 7;
                        sound(21);
                        }
                        else {cout << "Zbrojmistrz zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 51:
                        if(zloto >= 10)
                        {
                        cout << "Twoj pacnerz wzrosl o 5 pkt.!";
                        arm = arm + 5;
                        zloto = zloto - 10;
                        sound(21);
                        }
                        else {cout << "Zbrojmistrz zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 52:
                        if(zloto >= 14)
                        {
                        cout << "Twoj pacnerz wzrosl o 7 pkt.!";
                        arm = arm + 7;
                        zloto = zloto - 14;
                        sound(21);
                        }
                        else {cout << "Zbrojmistrz zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 53:
                        if(zloto >= 30)
                        {
                        cout << "Twoj pacnerz wzrosl o 14 pkt.!";
                        arm = arm + 14;
                        zloto = zloto - 30;
                        sound(21);
                        }
                        else {cout << "Zbrojmistrz zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(19);}
                        break;
                    case 54:
                        cout << "Bog z toba wedrowcze!";
                        sound(21);
                        break;
                    default:
                        goto sklepo;
                 }
                 break;
        case 3:
            statystyki();
            cout << "\nSpotykasz na swej drodze uzdrowiciela, oferuje Ci mozliwosc uleczenia twych ran w zamian za niewielka oplate:\n"
                 << "[1] +5 pkt. zdrowia - 3 szt. zlota\n"
                 << "[2] +10 pkt. zdrowia - 5 szt. zlota\n"
                 << "[3] +15 pkt. zdrowia - 7 szt. zlota\n"
                 << "[4] +25 pkt. zdrowia - 12 szt. zlota\n"
                 << "[5] +50 pkt. zdrowia - 25 szt. zlota\n"
                 << "[6] Bywaj!\n"
                 << "\nIlosc posiadanego przez ciebie zlota: " << zloto << endl;
            sound(24);
            zakup = getch();
            system("cls");
                 switch(zakup)
                 {
                    case 49:
                        if(zloto >= 3)
                        {
                        cout << "Twoje zycie zwieksza sie! Otrzymales dodatkowe 5 pkt. zdrowia!";
                        hp = hp + 5;
                        zloto = zloto - 3;
                        sound(21);
                        }
                        else {cout << "Uzdrowiciel zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(20);}
                        break;
                    case 50:
                        if(zloto >= 5)
                        {
                        cout << "Twoje zycie zwieksza sie! Otrzymales dodatkowe 10 pkt. zdrowia!";
                        hp = hp + 10;
                        zloto = zloto - 5;
                        sound(21);
                        }
                        else {cout << "Uzdrowiciel zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(20);}
                        break;
                    case 51:
                        if(zloto >= 7)
                        {
                        cout << "Twoje zycie zwieksza sie! Otrzymales dodatkowe 15 pkt. zdrowia!";
                        hp = hp + 15;
                        zloto = zloto - 7;
                        sound(21);
                        }
                        else {cout << "Uzdrowiciel zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(20);}
                        break;
                    case 52:
                        if(zloto >= 12)
                        {
                        cout << "Twoje zycie zwieksza sie! Otrzymales dodatkowe 25 pkt. zdrowia!";
                        hp = hp + 25;
                        zloto = zloto - 12;
                        sound(21);
                        }
                        else {cout << "Uzdrowiciel zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(20);}
                        break;
                    case 53:
                        if(zloto >= 25)
                        {
                        cout << "Twoje zycie zwieksza sie! Otrzymales dodatkowe 50 pkt. zdrowia!";
                        hp = hp + 50;
                        zloto = zloto - 25;
                        sound(21);
                        }
                        else {cout << "Uzdrowiciel zauwaza ze chcesz go oszukac i odchodzi!";
                        sound(20);}
                        break;
                    case 54:
                        cout << "Bog z toba wedrowcze!";
                        sound(21);
                        break;
                    default:
                        goto sklepo;
                 }
                 break;
    }
    klawisz();
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void akt_poziomk(void)
{
   if(akt_poziom == 1) cout << "Wkraczasz do mrocznego lasu. \nPoziom 1-1.";
   else if(akt_poziom > 1 and akt_poziom < 5) cout << "Mroczny las. \nPoziom 1-" << akt_poziom << ".";
   else if(akt_poziom == 5) cout << "Zauwazasz wejscie do podziemii. Strzeze go jednak przerazliwe monstrum. \nPoziom 1-5.";
   else if(akt_poziom > 5 and akt_poziom < 10) cout << "Podziemia. \nPoziom 2-" << akt_poziom - 5 << ".";
   else if(akt_poziom == 10) cout << "Zauwazasz ogromne epicko wygladajace drzwi. Sa one jednak dobrze strzezone. \nPoziom 2-5.";
   else if(akt_poziom > 10 and akt_poziom < 15) cout << "Sala tronowa. \nPoziom 3-" << akt_poziom - 10 << ".";
   else if(akt_poziom == 15) cout << "Wreszcie docierasz do celu...\nTo na ten moment byles przez caly ten czas przygotowywany.\nCelem twojego zycia bylo stoczyc ten wlasnie pojedynek!\nPoziom 3-5.";
   else if(akt_poziom > 15 and akt_poziom < 20) cout << "Magiczna kraina. \nPoziom 4-" << akt_poziom - 15 << ".";
   else if(akt_poziom == 20) cout << "Spotykasz na swej drodze krula kucykolandii i wyzywasz go na pojedynek!\nPoziom 4-5.";
   klawisz();
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void klawisz(void)
{
   cout << "\n\nWcisnij dowolny klawisz aby kontynuuowac...";
   getch();
   system("cls");
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void potwor(void)
{
    short int nr_potwora;
    if(akt_poziom >= 1 and akt_poziom <= 4)
    {
        nr_potwora = rand() % 6 + 1;
        switch(nr_potwora)
        {
            case 1:
                eimie = "Pajak";
                ehp = 25;
                earm = 7;
                eatk = 7;
                monster_type = 1;
                break;
            case 2:
                eimie = "Wilk";
                ehp = 15;
                earm = 8;
                eatk = 8;
                monster_type = 1;
                break;
            case 3:
                eimie = "Drzewiec";
                ehp = 30;
                earm = 7;
                eatk = 6;
                monster_type = 1;
                break;
            case 4:
                eimie = "Leprechaun";
                ehp = 10;
                earm = 10;
                eatk = 11;
                monster_type = 3;
                break;
            case 5:
                eimie = "Mroczny Elf";
                ehp = 20;
                earm = 8;
                eatk = 7;
                monster_type = 3;
                break;
            case 6:
                eimie = "Zlowrogi Zajac";
                ehp = 15;
                earm = 7;
                eatk = 9;
                monster_type = 1;
                break;
        }
    }
    else if(akt_poziom == 5)
    {
                eimie = "Ogromna Tarantula";
                ehp = 50;
                earm = 9;
                eatk = 12;
                monster_type = 1;
    }
    else if(akt_poziom >= 6 and akt_poziom <= 9)
    {
        nr_potwora = rand() % 6 + 1;
        switch(nr_potwora)
        {
            case 1:
                eimie = "Szkielet";
                ehp = 40;
                earm = 9;
                eatk = 13;
                monster_type = 2;
                break;
            case 2:
                eimie = "Krwiozerczy Nietoperz";
                ehp = 20;
                earm = 8;
                eatk = 18;
                monster_type = 1;
                break;
            case 3:
                eimie = "Nekromanta";
                ehp = 20;
                earm = 11;
                eatk = 15;
                monster_type = 3;
                break;
            case 4:
                eimie = "Leprechaun";
                ehp = 15;
                earm = 14;
                eatk = 17;
                monster_type = 3;
                break;
            case 5:
                eimie = "Wampir";
                ehp = 25;
                earm = 12;
                eatk = 13;
                monster_type = 2;
                break;
            case 6:
                eimie = "Zombie";
                ehp = 35;
                earm = 12;
                eatk = 11;
                monster_type = 2;
                break;
        }
    }
    else if(akt_poziom == 10)
    {
                eimie = "Martwy Cerber";
                ehp = 50;
                earm = 18;
                eatk = 17;
                monster_type = 2;
    }
    else if(akt_poziom >= 11 and akt_poziom <= 14)
    {
        nr_potwora = rand() % 6 + 1;
        switch(nr_potwora)
        {
            case 1:
                eimie = "Nieumarly Sluga";
                ehp = 40;
                earm = 18;
                eatk = 22;
                monster_type = 2;
                break;
            case 2:
                eimie = "Gwardzista";
                ehp = 60;
                earm = 18;
                eatk = 18;
                monster_type = 3;
                break;
            case 3:
                eimie = "Szlachcic";
                ehp = 10;
                earm = 10;
                eatk = 10;
                monster_type = 3;
                break;
            case 4:
                eimie = "Leprechaun";
                ehp = 25;
                earm = 21;
                eatk = 21;
                monster_type = 3;
                break;
            case 5:
                eimie = "Ogromny Nietoperz";
                ehp = 30;
                earm = 18;
                eatk = 24;
                monster_type = 1;
            case 6:
                eimie = "Ogar";
                ehp = 40;
                earm = 16;
                eatk = 24;
                monster_type = 1;
        }
    }
    else if(akt_poziom == 15)
    {
                eimie = simie;
                ehp = hp;
                earm = arm;
                eatk = atk;
                monster_type = 3;
    }
    else if(akt_poziom >= 16 and akt_poziom <= 19)
    {
        nr_potwora = rand() % 6 + 1;
        switch(nr_potwora)
        {
            case 1:
                eimie = "Kucyk";
                ehp = 80;
                earm = 30;
                eatk = 48;
                monster_type = 1;
                break;
            case 2:
                eimie = "Jezdziec Kucykow";
                ehp = 120;
                earm = 36;
                eatk = 36;
                monster_type = 3;
                break;
            case 3:
                eimie = "Doradca Krula";
                ehp = 20;
                earm = 20;
                eatk = 20;
                monster_type = 3;
                break;
            case 4:
                eimie = "Leprechaun";
                ehp = 50;
                earm = 42;
                eatk = 42;
                monster_type = 3;
                break;
            case 5:
                eimie = "Kuc - Nie Do Pokonania Kuc";
                ehp = 160;
                earm = 60;
                eatk = 96;
                monster_type = 1;
                break;
            case 6:
                eimie = "Zombie Kuc";
                ehp = 80;
                earm = 30;
                eatk = 48;
                monster_type = 2;
        }
    }
    else if(akt_poziom == 20)
    {
                eimie = "Krul Korwin";
                ehp = hp/1.5;
                earm = arm*1.5;
                eatk = atk*1.5;
                monster_type = 3;
    }
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void nagroda(void)
{
    short int reg;
    short int nagroda_item = rand() % 20+1;
    if(ucieczka == 0)
    {
    short int nagroda_dod = rand() % 20+1;
    if(eimie == "Leprechaun")
    {
    zloto = zloto + eatk * 0.70 + earm * 0.70;
    cout << "Znajdujesz worek pe≥en z≥ota! Zdobywasz: " << eatk * 0.70 + earm * 0.70 << " szt. zlota!";
    }
    else
    {
    zloto = zloto + eatk * 0.50 + earm * 0.50;
    cout << "Po walce przeszukujesz zwloki przeciwnika i znajdujesz: " << eatk * 0.50 + earm * 0.50 << " szt. zlota!";
    }
    if(nagroda_item >= 9)
    {
        itemdrop();
        cout << "\n\nZnajdujesz rowniez przedmiot: " << item << "!";
    }
    if(nagroda_dod >= 13)
    {
        nagroda_dod = rand() % 3+1;
        cout << "\n";
        switch(nagroda_dod)
        {
            case 1:
                atk = atk + 1;
                cout << "\nDodatkowo twoja umiejetnosc walki wzrosla o 1!";
                break;
            case 2:
                arm = arm + 1;
                cout << "\nDodatkowo twoja zdolnosc obrony wzrosla o 1!";
                break;
            case 3:
                hp = hp + 5;
                cout << "\nDodatkowo twoje zdrowie zwiekszylo sie o 5!";
                break;
        }
    }
    if(klasa == 50)
    {
        reg = rand() % 15 + 11;
        cout << "\n\nOdpoczywajac regenerujesz " << reg << " pkt. energii.";
        energy = energy + reg;
        if(energy > 100) energy = 100;

    }
    if(klasa == 51)
    {
        reg = rand() % 15 + 11;
        cout << "\n\nOdpoczywajac regenerujesz " << reg << " pkt. many.";
        mp = mp + reg;
        if(mp > 100) mp = 100;
    }
    }
    else if (ucieczka == 1)
    {
        if(eimie == "Leprechaun")
        {
        zloto = zloto + eatk * 0.35 + earm * 0.35;
        cout << "Uciekajac udaje Ci sie ukrasc worek pelen zlota! Zdobywasz: " << eatk * 0.35 + earm * 0.35 << " szt. zlota!";
        }
        else
        {
        zloto = zloto + eatk * 0.25 + earm * 0.25;
        cout << "Uciekajac udaje Ci sie ukrasc przeciwnikowi: " << eatk * 0.25 + earm * 0.25 << " szt. zlota!";
        }
        if(nagroda_item >= 9)
        {
        itemdrop();
        cout << "\n\nDodatkowo udaje ci sie wykrasc rowniez przedmiot: " << item << "!";
        }
    }
    klawisz();
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void klasy(void)
{
    cout << "[1] Barbarzynca - silny i wytrzymaly, \nwalczy glownie w zwarciu, \nzadaje dodatkowe obrazenia ludziom, \nkorzysta ze swej zlosci by pokonac przeciwnika\n" << endl
         << "[2] Lowca - szybki i zwinny, \nsprawny w walce w zwarciu jak i na odleglosc, \nzadaje dodatkowe obrazenia bestiom, \nkorzysta z energii by wyprowadzac kolejne ataki\n" << endl
         << "[3] Mag - niska wytrzymalosc nadrabia wysokimi obrazeniami, \nzadaje dodatkowe obrazenia nieumarlym, \nkorzystna z many by miotac we wszystkie strony kulami ognia\n" << endl
         << "Ktora klase wybierasz? ";
wybor:
    klasa = getch();
    if(klasa == 49)
    {
    hp = 45;
    atk = 9;
    arm = 9;
    rage = 50;
    mp = 0;
    energy = 0;
    }
    else if(klasa == 50)
    {
    hp = 45;
    atk = 11;
    arm = 7;
    rage = 0;
    mp = 0;
    energy = 50;
    }
    else if(klasa == 51)
    {
    hp = 45;
    atk = 13;
    arm = 4;
    rage = 0;
    mp = 50;
    energy = 0;
    }
    else goto wybor;
    system("cls");
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void barbarzynca(void)
{
    short int opcja;
    short int tekst;
    short int rzut;
    short int ehps = ehp;
    short int reg;
    do
    {
wybor:
    if(hp > 130) hp = 130;
    atk_type = 1;
    cout << "~~ " << imie << " ~~" << endl
         << "Zdrowie: " << hp << "/130" << endl
         << "Atak: " << atk << endl
         << "Pancerz: " << arm << endl
         << "Zlosc: " << rage << "/100" << endl
         << "Przedmiot: " << item << endl
         << "\n" << endl
         << "~~ " << eimie << " ~~" << endl
         << "Zdrowie: " << ehp << "/" << ehps << endl
         << "Atak: " << eatk << endl
         << "Pancerz: " << earm << endl
         << "\n" << endl
         << "[1] Atak mieczem" << endl
         << "[2] Miazdzace uderzenie(25 pkt. zlosci)" << endl
         << "[3] Przeszywajacy cios(25 pkt. zlosci)" << endl
         << "[4] Szalona regeneracja(15 pkt. zlosci)" << endl
         << "[5] Uzyj przedmiotu" << endl
         << "[6] Ucieczka" << endl;
    opcja = getch();
    system("cls");
    switch(opcja)
    {
        case 49:
            cout << imie << ":\n";
            sound(7);
            atk_type = 1;
            dmg = atk * 1.35 - earm + 0.5;
            if(monster_type == 3) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Szarzujesz na wroga i zadajesz mu " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Szybkie pchniecie i wrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Kolejny celny cios. Przeciwnik traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            reg = rand() % 11;
            cout << "Twoja zlosc rosnie o " << reg << " pkt...\n";
            rage = rage + reg;
            if(rage > 100) rage = 100;
            }
            if(dmg <= 0) cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            break;
        case 50:
            cout << imie << ":\n";
            if(rage >= 25)
            {
            rage = rage - 25;
            atk_type = 1;
            dmg = atk * 1.85 - earm + 0.5;
            if(monster_type == 3) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "To bylo istnie miazdzace uderzenie, przeciwnik nie ma sily sie nawet podniesc.\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 2:
                    cout << "Kto by pomyslal ze masz w sobie tyle sily? \nZadajesz " << dmg << " obrazen." << endl;
                    break;
                case 3:
                    cout << "Twoj mocarny cios zwala przeciwnika z nog.\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo zlosci by wykonac ten atak!" << endl;
            break;
        case 51:
            cout << imie << ":\n";
            if(rage >= 25)
            {
            sound(7);
            rage = rage - 25;
            atk_type = 1;
            dmg = atk * 1.5 - earm/2 + 0.5;
            if(monster_type == 3) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Przebijasz sie przez pancerz wroga i zadajesz mu " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Zauwazasz slaby pkt. wroga i wykonujesz celne pchniecie. \nWrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Szybki i bezbledny cios.\n Przeciwnik traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo zlosci by wykonac ten atak!" << endl;
            break;
        case 52:
            cout << imie << ":\n";
            if(rage >= 15)
            {
            sound(13);
            rage = rage - 15;
            atk_type = 2;
            dmg = 0.40*atk + 0.40*arm + 0.5;
            hp = hp + dmg;
            cout << "Regenerujesz " << dmg << " pkt. zdrowia!" << endl;
            }
            else cout << "Masz za malo zlosci by sie regenerowac!" << endl;
            break;
        case 53:
            cout << imie << ":\n";
            useitem();
            break;
        case 54:
            cout << imie << ":\n";
            cout << "Wykonujesz rzut na ucieczke(k20, powodzenie 11+)..." << endl;
            rzut = rand() % 20 + 1;
            sound(14)
            cout << "Wyrzuciles " << rzut << "..." << endl;
            if(rzut >= 11)
            {
                cout << "Ucieczka zakonczona sukcesem!";
                ucieczka = 1;
                klawisz();
                return;
            }
            else
            {
                cout << "Nie udaje Ci sie uciec..." << endl;
            }
            break;
        default:
            goto wybor;
    }
    wrog();
    klawisz();
    }
    while(hp > 0 and ehp > 0);
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void lowca(void)
{
    short int opcja;
    short int tekst;
    short int rzut;
    short int ehps = ehp;
    do
    {
wybor:
    if(hp > 120) hp = 120;
    atk_type = 1;
    cout << "~~ " << imie << " ~~" << endl
         << "Zdrowie: " << hp << "/120" << endl
         << "Atak: " << atk << endl
         << "Pancerz: " << arm << endl
         << "Energia: " << energy << "/100" << endl
         << "Przedmiot: " << item << endl
         << "\n" << endl
         << "~~ " << eimie << " ~~" << endl
         << "Zdrowie: " << ehp << "/" << ehps << endl
         << "Atak: " << eatk << endl
         << "Pancerz: " << earm << endl
         << "\n" << endl
         << "[1] Atak sztyletem" << endl
         << "[2] Smiertelny cios(15 pkt. energii)" << endl
         << "[3] Przeszywajaca strzal(25 pkt. energii)" << endl
         << "[4] Przyzwanie towarzysza(20 pkt. energii)" << endl
         << "[5] Uzyj przedmiotu" << endl
         << "[6] Ucieczka" << endl;
    opcja = getch();
    system("cls");
    switch(opcja)
    {
        case 49:
            cout << imie << ":\n";
            sound(7)
            atk_type = 1;
            dmg = atk * 1.35 - earm + 0.5;
            if(monster_type == 1) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Wbijasz przeciwnikowi noz w plecy. \nZadajesz " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Syzbki atak z zaskoczenia i wrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Prosto miedzy oczy. \nPrzeciwnik traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            break;
        case 50:
            cout << imie << ":\n";
            if(energy >= 15)
            {
            energy = energy - 15;
            atk_type = 1;
            dmg = atk * 1.85 - earm + 0.5;
            if(monster_type == 1) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Nawalnica ciosow zwala przeciwnika z nog. \nZadajesz " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Jeden celny cios i wrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Cios prosto w czuly pkt..\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo energii by wykonac ten atak!" << endl;
            break;
        case 51:
            cout << imie << ":\n";
            if(energy >= 25)
            {
            sound(9);
            energy = energy - 25;
            atk_type = 2;
            dmg = atk * 1.35 - earm/2 + 0.5;
            if(monster_type == 3) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 2 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Bez problemu trafiasz w czuly pkt. wroga. \nZadajesz " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Celnym trafieniem przebijasz sie przez pancerz przeciwnika. \nWrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo energii by wykonac ten atak!" << endl;
            break;
        case 52:
            cout << imie << ":\n";
            if(energy >= 20)
            {
            energy = energy - 20;
            if(companion == 1 or companion == 2)
            {
            cout << "Masz juz przywolana Bestie!" << endl;
            break;
            }
            sound(15);
            atk_type = 2;
            companion = 2;
            cout << "Przyzywasz Bestie!" << endl;
            }
            else cout << "Masz za malo energii by przyzwac Bestie!" << endl;
            break;
        case 53:
            cout << imie << ":\n";
            useitem();
            break;
        case 54:
            cout << imie << ":\n";
            cout << "Wykonujesz rzut na ucieczke(k20, powodzenie 11+)..." << endl;
            rzut = rand() % 20 + 1;
            sound(14);
            cout << "Wyrzuciles " << rzut << "..." << endl;
            if(rzut >= 11)
            {
                cout << "Ucieczka zakonczona sukcesem!";
                ucieczka = 1;
                klawisz();
                return;
            }
            else
            {
                cout << "Nie udaje Ci sie uciec..." << endl;
            }
            break;
        default:
            goto wybor;
    }
    if(companion == 2 or companion == 1) towarzysz();
    wrog();
    klawisz();
    }
    while(hp > 0 and ehp > 0);
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void mag(void)
{
    short int opcja;
    short int tekst;
    short int rzut;
    short int ehps = ehp;
    do
    {
wybor:
    if(hp > 110) hp = 110;
    atk_type = 1;
    cout << "~~ " << imie << " ~~" << endl
         << "Zdrowie: " << hp << "/110" << endl
         << "Atak: " << atk << endl
         << "Pancerz: " << arm << endl
         << "Mana: " << mp << "/100" << endl
         << "Przedmiot: " << item << endl
         << "\n" << endl
         << "~~ " << eimie << " ~~" << endl
         << "Zdrowie: " << ehp << "/" << ehps << endl
         << "Atak: " << eatk << endl
         << "Pancerz: " << earm << endl
         << "\n" << endl
         << "[1] Atak laska" << endl
         << "[2] Kula Ognia(25 pkt. many)" << endl
         << "[3] Przeszywajacy Piorun(25 pkt. many)" << endl
         << "[4] Przywolanie(20 pkt. many)" << endl
         << "[5] Uzyj przedmiotu" << endl
         << "[6] Ucieczka" << endl;
    opcja = getch();
    system("cls");
    switch(opcja)
    {
        case 49:
            cout << imie << ":\n";
            sound(8);
            atk_type = 1;
            dmg = atk * 1.35 - earm + 0.5;
            if(monster_type == 2) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Rzucasz sie na przeciwnika i zadajesz mu " << dmg << " obrazen!" << endl;
                    break;
                case 2:
                    cout << "Udaje ci sie celenie trafic wroga. \nTraci on " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Twoj cios kosturem wytraca przeciwnika z rownowagi.\n Wrog traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            break;
        case 50:
            cout << imie << ":\n";
            if(mp >= 25)
            {
            sound(16);
            mp = mp - 25;
            atk_type = 2;
            dmg = atk * 1.75 - earm + 0.5;
            if(monster_type == 2) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Ciskasz w przeciwnika kula ognia.\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 2:
                    cout << "Twoja kula ognia ledwo musnela wroga. \nTraci on jednak " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Kula ognia rozbija sie o przeciwnika.\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo many by wykonac ten czar!" << endl;
            break;
        case 51:
            cout << imie << ":\n";
            if(mp >= 25)
            {
            sound(18);
            mp = mp - 25;
            atk_type = 2;
            dmg = atk * 1.35 - earm/2 + 0.5;
            if(monster_type == 2) dmg = dmg + 3;
            randdmg();
            tekst = rand() % 3 + 1;
            if(dmg > 0)
            {
            switch(tekst)
            {
                case 1:
                    cout << "Ciskasz w przeciwnika piorunem.\n" << eimie << " traci " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 2:
                    cout << "Twoj piorun ledwo musnal wroga. \nTraci on jednak " << dmg << " pkt. zdrowia." << endl;
                    break;
                case 3:
                    cout << "Piorun trafia prosto w cel. \nPrzeciwnik traci " << dmg << " pkt. zdrowia." << endl;
                    break;
            }
            ehp = ehp - dmg;
            }
            else cout << "Atak zakonczony niepowodzeniem. Zadales 0 pkt. obrazen." << endl;
            }
            else cout << "Masz za malo many by wykonac ten czar!" << endl;
            break;
        case 52:
            cout << imie << ":\n";
            if(mp >= 20)
            {
            mp = mp - 20;
            if(companion == 1 or companion == 2)
            {
            cout << "Masz juz przywolanego Chowanca!" << endl;
            break;
            }
            sound(17);
            atk_type = 2;
            companion = 2;
            cout << "Przywolujesz Chowanca!" << endl;
            }
            else cout << "Masz za malo many by przywolac Chowanca!" << endl;
            break;
        case 53:
            cout << imie << ":\n";
            useitem();
            break;
        case 54:
            cout << imie << ":\n";
            cout << "Wykonujesz rzut na ucieczke(k20, powodzenie 11+)..." << endl;
            rzut = rand() % 20 + 1;
            sound(14);
            cout << "Wyrzuciles " << rzut << "..." << endl;
            if(rzut >= 11)
            {
                cout << "Ucieczka zakonczona sukcesem!";
                ucieczka = 1;
                klawisz();
                return;
            }
            else
            {
                cout << "Nie udaje Ci sie uciec..." << endl;
            }
            break;
        default:
            goto wybor;
    }
    if(companion == 2 or companion == 1) towarzysz();
    wrog();
    klawisz();
    }
    while(hp > 0 and ehp > 0);
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void wrog(void)
{
    short int tekst;
    cout << "\n" << eimie << ":\n";
    dmg = (int)(eatk * 1.6 - arm/1.3 + 0.5);
    if(atk_type == 1)
    {
    if(monster_type == 1) sound(10);
    if(monster_type == 2) sound(12);
    if(monster_type == 3) sound(11);
    if(dmg > 0)
    {
    randdmg();
    tekst = rand() % 3 + 1;
    switch(tekst)
    {
        case 1:
            cout << "Wrog byl tak szybki ze nie zdazyles nawet uniknac kontrataku. \nTracisz " << dmg << " pkt. zdrowia.";
            break;
        case 2:
            cout << "Szybka odpowiedz przeciwnika i zostajesz powalony na kolana. \nTracisz " << dmg << " pkt. zdrowia.";
            break;
        case 3:
            cout << "Kolejne ciecie, kolejna rana. \nOtrzymujesz " << dmg << " obrazen!";
            break;
    }
    hp = hp - dmg;
    }
    else cout << "Atak wroga zakonczyl sie niepowodzeniem. \nOtrzymujesz 0 pkt. obrazen.";
    }
    else cout << "Przeciwnik jest zbyt daleko od ciebie by wykonac atak!";
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void towarzysz(void)
{
    short int tekst;
    if(klasa == 50)
    {
    cout << "\nBestia:\n";
    sound(10);
    dmg = 0.6 * atk;
    randdmg();
    tekst = rand() % 3 + 1;
    switch(tekst)
    {
        case 1:
            cout << "Rzuca sie na przeciwnika i zadaje mu " << dmg << " obrazen." << endl;
            break;
        case 2:
            cout << "Swoimi klami rozdiera przeciwnikowi cialo. \nTraci tym samym " << dmg << " pkt. zdrowia." << endl;
            break;
        case 3:
            cout << "Swoim cielskiem przewraca wroga. Przeciwnik traci " << dmg << " pkt. zdrowia!" << endl;
            break;
    }
    }
    if(klasa == 51)
    {
    cout << "\nChowaniec:\n";
    sound(16);
    dmg = 0.6 * atk;
    randdmg();
    cout << "Ciska kula ognia w przeciwnika. \nZadaje " << dmg << " obrazen." << endl;
    }
    ehp = ehp - dmg;
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void itemdrop(void)
{
    short int tekst;

    tekst = rand() % 12 + 1;

    switch(tekst)
    {
        case 1:
            item = "Mala mikstura zdrowia";
            itemnr = 1;
            break;
        case 2:
            item = "Srednia mikstura zdrowia";
            itemnr = 2;
            break;
        case 3:
            item = "Duza mikstura zdrowia";
            itemnr = 3;
            break;
        case 4:
            item = "Mikstura sily";
            itemnr = 4;
            break;
        case 5:
            item = "Mikstura wytrzymalosci";
            itemnr = 5;
            break;
        case 6:
            item = "Laser";
            itemnr = 6;
            break;
        case 7:
            item = "Kamyk";
            itemnr = 7;
            break;
        case 8:
            item = "Zwoj kuli ognia";
            itemnr = 8;
            break;
        case 9:
            item = "Zwoj przeszywajacego pioruna";
            itemnr = 9;
            break;
        case 10:
            item = "Zwoj czaru rozbrojenia";
            itemnr = 10;
            break;
        case 11:
            item = "Zwoj czaru oslabienia";
            itemnr = 11;
            break;
        case 12:
            item = "Mikstura regeneracji";
            itemnr = 12;
            break;
    }
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void useitem(void)
{
    atk_type = 2;
    switch(itemnr)
    {
        case 0:
            atk_type = 1;
            cout << "Nie masz przedmiotu do uzycia!" << endl;
            break;
        case 1:
            hp = hp + 10;
            cout << "Mikstura uleczyla 10 pkt. zdrowia." << endl;
            break;
        case 2:
            hp = hp + 20;
            cout << "Mikstura uleczyla 20 pkt. zdrowia." << endl;
            break;
        case 3:
            hp = hp + 30;
            cout << "Mikstura uleczyla 30 pkt. zdrowia." << endl;
            break;
        case 4:
            atk = atk + 3;
            cout << "Twoj atak wzrosl o 3 pkt.!" << endl;
            break;
        case 5:
            arm = arm + 3;
            cout << "Twoja obrona wzrosla o 3 pkt.!" << endl;
            break;
        case 6:
            dmg = 1.2 * atk - arm/2 + 0.5;
            randdmg();
            ehp = ehp - dmg;
            cout << "Pif-Paf! Laser urywa przeciwnikowi reke i zadaje " << dmg << "pkt. obrazen!" << endl;
            break;
        case 7:
            cout << "Twoj kamien jedynie rozwscieczyl wroga!" << endl;
            break;
        case 8:
            dmg = 1.6 * atk - arm + 0.5;
            randdmg();
            ehp = ehp - dmg;
            cout << "Uzywasz zwoju...\nTwoja kula ognia trafia prosto w przeciwnika i rani go za " << dmg << " pkt. obrazen!" << endl;
            break;
        case 9:
            dmg = 1.2 * atk - arm/2 + 0.5;
            randdmg();
            ehp = ehp - dmg;
            cout << "Uzywasz zwoju...\nTwoj przeszywajacy piorun przechodzi przez zbroje przeciwnika i zadaje " << dmg << " obrazen!" << endl;
            break;
        case 10:
            eatk = 0;
            cout << "Uzywasz zwoju...\nRozbrajasz przeciwnika!" << endl;
            break;
        case 11:
            eatk = (int)(eatk/2 + 0.5);
            earm = (int)(earm/2 + 0.5);
            cout << "Uzywasz zwoju...\nAtak i obrona przeciwnika zmniejszaja sie!" << endl;
            break;
        case 12:
            if(klasa == 49) cout << "Wypijasz miksture i...\nNic sie nie dzieje..." << endl;
            else if(klasa == 50) {cout << "Wypijasz miksture i regenerujesz 25 pkt. energii!" << endl; energy = energy + 25;}
            else if(klasa == 51) {cout << "Wypijasz miksture i regenerujesz 25 pkt. many!" << endl; mp = mp + 25;}
            break;
    }
    itemnr = 0;
    item = "Brak";
}
//*****************************************************************************************************************************************************************************************************
//*****************************************************************************************************************************************************************************************************
void soundeffect(int ktory)
{
    sf::SoundBuffer buffer;
    switch(ktory)
    {
    case 1:
        music.openFromFile("sounds/bg/las.wav");
        music.play();
        music.setLoop(true);
        break;
    case 2:
        music.openFromFile("sounds/bg/intro.wav");
        music.play();
        music.setLoop(true);
        break;
    case 3:
        music.openFromFile("sounds/bg/jaskinia.wav");
        music.play();
        music.setLoop(true);
        break;
    case 4:
        music.openFromFile("sounds/bg/sala.wav");
        music.play();
        music.setLoop(true);
        break;
    case 5:
        music.openFromFile("sounds/bg/kucolandia.wav");
        music.play();
        music.setLoop(true);
        break;
    case 6:
        music.openFromFile("sounds/bg/zgon.wav");
        music.play();
        music.setLoop(true);
        break;
    case 7:
        buffer.loadFromFile("sounds/atak/sword.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 8:
        buffer.loadFromFile("sounds/atak/staff.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 9:
        buffer.loadFromFile("sounds/atak/arrow.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 10:
        buffer.loadFromFile("sounds/wrog/bite.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 11:
        buffer.loadFromFile("sounds/wrog/punch.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 12:
        buffer.loadFromFile("sounds/wrog/undead.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 13:
        buffer.loadFromFile("sounds/rage.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 14:
        buffer.loadFromFile("sounds/escape.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 15:
        buffer.loadFromFile("sounds/whistle.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 16:
        buffer.loadFromFile("sounds/magia/fireball.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 17:
        buffer.loadFromFile("sounds/magia/summon.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 18:
        buffer.loadFromFile("sounds/magia/thunder.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 19:
        buffer.loadFromFile("sounds/npc/getout.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 20:
        buffer.loadFromFile("sounds/npc/getout2.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 21:
        buffer.loadFromFile("sounds/npc/goodbye.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 22:
        buffer.loadFromFile("sounds/npc/greetings.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 23:
        buffer.loadFromFile("sounds/npc/welcome.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    case 24:
        buffer.loadFromFile("sounds/npc/what.wav");
        short_music.setBuffer(buffer);
        short_music.play();
        while(short_music.getStatus() == sf::Sound::Playing){}
        break;
    }
}
