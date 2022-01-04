#pragma once

#include "grafic.h"

using namespace std;

FILE* fin = fopen("date.in", "r");
FILE* fout = fopen("date.out", "w");

/// /////////////

void vectorizare(char s[], char v[NMAX][LMAX], int& k);
bool operand(char c);
bool functie(string c);
bool operand(string c);
void testare(char s[], char v[NMAX][LMAX], int& i, int& k);
float stringToNumber(char sir[]);
arb arborizare(char v[NMAX][LMAX], int poz);
void inordine(arb a);
arb derivare(arb a);
queue < string > postfix(char v[NMAX][LMAX], int lungime);
arb copiere(arb a);
arb simplificare_partiala(arb a);
void simplificare(arb& a);
void previous(arb& a);
int priorit(string c);
string parantezare(queue <string> coada);
void afisare_stiva(stack <string> s);
void output(arb a);
void citire(char s[]);
void derivare_functie(char s[], int ordin);
void stringtochar(string str, char Sir[]);
string numberToString(float numar);
int menu();

/// ///////////// -x

int menu()
{
    char s[NMAX];
    int cateori;

    /*
    strcpy(s, "-1.23*x");
    cateori = 1;
    variabila_derivare = 'x';
    derivare_functie(s, 1);
    cout << siroutput;
    fereastra(arbore_output);
    */

    RenderWindow window(VideoMode(1200, 800), "Proiect DERIV");
    bool limba = 0;
    bool fontul = 0;
    int randuri = 0;

    Font font;
    if (!font.loadFromFile("Antaro.ttf"))
        return EXIT_FAILURE;

    Texture texture;
    if (!texture.loadFromFile("math.jpg"))
        return EXIT_FAILURE;
    Sprite sprite(texture);

    Texture imgro;
    if (!imgro.loadFromFile("ro.png"))
        return EXIT_FAILURE;
    Sprite spritero(imgro);
    spritero.setPosition(880, 685);

    Texture imgen;
    if (!imgen.loadFromFile("en.png"))
        return EXIT_FAILURE;
    Sprite spriteen(imgen);
    spriteen.setPosition(1030, 685);

    RectangleShape introdu;
    introdu.setSize(Vector2f(1120, 110));
    introdu.setFillColor(Color::Black);
    introdu.setPosition(40, 40);

    RectangleShape functiede;
    functiede.setSize(Vector2f(660, 80));
    functiede.setFillColor(Color::Black);
    functiede.setPosition(40, 170);

    RectangleShape decateori;
    decateori.setSize(Vector2f(430, 80));
    decateori.setFillColor(Color::Black);
    decateori.setPosition(730, 170);

    RectangleShape casetaderivare;
    casetaderivare.setSize(Vector2f(1120, 300));
    casetaderivare.setFillColor(Color::Black);
    casetaderivare.setPosition(40, 270);

    RectangleShape casetainfo;
    casetainfo.setSize(Vector2f(260, 170));
    casetainfo.setFillColor(Color::Black);
    casetainfo.setPosition(40, 590);

    RectangleShape casetasave;
    casetasave.setSize(Vector2f(260, 170));
    casetasave.setFillColor(Color::Black);
    casetasave.setPosition(315, 590);

    RectangleShape casetaarbore;
    casetaarbore.setSize(Vector2f(260, 170));
    casetaarbore.setFillColor(Color::Black);
    casetaarbore.setPosition(590, 590);

    RectangleShape casetafont;
    casetafont.setSize(Vector2f(290, 75));
    casetafont.setFillColor(Color::Black);
    casetafont.setPosition(870, 590);

    /// romana 

    Text textintrodu(" Introduceti functia:", font, 35);
    textintrodu.setFillColor(Color::White);
    textintrodu.setPosition(50, 70);

    Text textfunctiede("  Deriveaza in functie de:", font, 25);
    textfunctiede.setFillColor(Color::White);
    textfunctiede.setPosition(50, 195);

    Text textdecateori("  De cate ori:", font, 25);
    textdecateori.setFillColor(Color::White);
    textdecateori.setPosition(740, 195);

    Text textcasetaderivare("  Derivata:", font, 35);
    textcasetaderivare.setFillColor(Color::White);
    textcasetaderivare.setPosition(50, 290);

    Text textcasetainfo("  Informatii", font, 30);
    textcasetainfo.setFillColor(Color::White);
    textcasetainfo.setPosition(90, 650);

    Text textcasetasave("Salveaza\n in fisier", font, 30);
    textcasetasave.setFillColor(Color::White);
    textcasetasave.setPosition(400, 630);

    Text textcasetaarbore("   Deseneaza\n      arbore", font, 30);
    textcasetaarbore.setFillColor(Color::White);
    textcasetaarbore.setPosition(650, 630);

    Text textcasetafont("Schimbare font", font, 30);
    textcasetafont.setFillColor(Color::White);
    textcasetafont.setPosition(930, 605);

    /// in engleza

    Text entextintrodu(" Insert function here:", font, 35);
    entextintrodu.setFillColor(Color::White);
    entextintrodu.setPosition(50, 70);

    Text entextfunctiede("  Differentiation variable:", font, 25);
    entextfunctiede.setFillColor(Color::White);
    entextfunctiede.setPosition(50, 195);

    Text entextdecateori("  Times: ", font, 25);
    entextdecateori.setFillColor(Color::White);
    entextdecateori.setPosition(740, 195);

    Text entextcasetaderivare("  Derivative:", font, 35);
    entextcasetaderivare.setFillColor(Color::White);
    entextcasetaderivare.setPosition(50, 290);

    Text entextcasetainfo("  Info", font, 30);
    entextcasetainfo.setFillColor(Color::White);
    entextcasetainfo.setPosition(120, 650);

    Text entextcasetasave("  Save\n  in file", font, 30);
    entextcasetasave.setFillColor(Color::White);
    entextcasetasave.setPosition(400, 630);

    Text entextcasetaarbore("Draw\n Tree", font, 30);
    entextcasetaarbore.setFillColor(Color::White);
    entextcasetaarbore.setPosition(675, 630);

    Text entextcasetafont("Change font", font, 30);
    entextcasetafont.setFillColor(Color::White);
    entextcasetafont.setPosition(950, 605);

    Event event;
    String userinput;
    Text usertext;
    usertext.setFont(font);
    usertext.setFillColor(Color::Cyan);

    String userinputfde;
    Text usertextfde;
    usertextfde.setFont(font);
    usertextfde.setFillColor(Color::Cyan);

    String userinputori;
    Text usertextori;
    usertextori.setFont(font);
    usertextori.setFillColor(Color::Cyan);

    Text usertextoutput;
    usertextoutput.setFont(font);
    usertextoutput.setFillColor(Color::Cyan);
    usertextoutput.setCharacterSize(35);

    string siroutput1;
    Text usertextoutput1;
    usertextoutput1.setFont(font);
    usertextoutput1.setFillColor(Color::Cyan);
    usertextoutput1.setCharacterSize(35);

    string siroutput2;
    Text usertextoutput2;
    usertextoutput2.setFont(font);
    usertextoutput2.setFillColor(Color::Cyan);
    usertextoutput2.setCharacterSize(35);

    string siroutput3;
    Text usertextoutput3;
    usertextoutput3.setFont(font);
    usertextoutput3.setFillColor(Color::Cyan);
    usertextoutput3.setCharacterSize(35);

    string sirfunctie;
    string sirfde;
    string sirori;

    Vector2f mp;
    mp.x = Mouse::getPosition(window).x;
    mp.y = Mouse::getPosition(window).y;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            mp.x = Mouse::getPosition(window).x;
            mp.y = Mouse::getPosition(window).y;

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
            {
                if (isSpriteHover(introdu.getGlobalBounds(), mp))
                {
                    usertext.setPosition(360, 75);
                }
                if (isSpriteHover(functiede.getGlobalBounds(), mp))
                {
                    usertextfde.setPosition(330, 190);
                }
                if (isSpriteHover(decateori.getGlobalBounds(), mp))
                {
                    usertextori.setPosition(900, 190);
                }
                if (isSpriteHover(casetaderivare.getGlobalBounds(), mp))
                {
                    sirfunctie = userinput;
                    sirfde = userinputfde;
                    sirori = userinputori;
                    siroutput.clear();

                    stringtochar(sirfunctie, s);
                    variabila_derivare = sirfde[0];
                    cateori = (int)(sirori[0] - '0');
                    derivare_functie(s, cateori);

                    if (siroutput.length() <= 70)
                    {
                        randuri = 1;
                        siroutput1.assign(siroutput);

                        usertextoutput1.setString(siroutput1);
                        usertextoutput1.setPosition(70, 340);
                    }
                    else if (siroutput.length() <= 140)
                    {
                        randuri = 2;
                        siroutput1.assign(siroutput, 0, 70);
                        siroutput2.assign(siroutput, 70, 70);

                        usertextoutput1.setString(siroutput1);
                        usertextoutput1.setPosition(70, 340);

                        usertextoutput2.setString(siroutput2);
                        usertextoutput2.setPosition(70, 390);
                    }
                    else
                    {
                        randuri = 3;
                        siroutput1.assign(siroutput, 0, 70);
                        siroutput2.assign(siroutput, 70, 70);
                        siroutput3.assign(siroutput, 140, 70);

                        usertextoutput1.setString(siroutput1);
                        usertextoutput1.setPosition(70, 340);

                        usertextoutput2.setString(siroutput2);
                        usertextoutput2.setPosition(70, 390);

                        usertextoutput3.setString(siroutput3);
                        usertextoutput3.setPosition(70, 440);
                    }
                }
                if (isSpriteHover(casetaarbore.getGlobalBounds(), mp))
                {
                    fereastra(arbore_output);
                }
                if (isSpriteHover(casetainfo.getGlobalBounds(), mp))
                {
                    RectangleShape casetainfos;
                    casetainfos.setSize(Vector2f(720, 520));
                    casetainfos.setFillColor(Color::Black);
                    casetainfos.setPosition(40, 40);

                    Text textinfos("- pentru a folosi programul trebuie sa apasati pe caseta in care \nvreti sa introduceti text;\n- pentru a deriva functia apasati in interiorul casetei derivata; \n- pentru a deriva alta functie trebuie sters inputul initial si rescris; \n- pentru numere reale folositi separatorul '.'(nu ',' );\n- precizia numerelor reale este de 2 zecimale; \n- functii permise : sin, cos, tg, ctg, ln, sqrt; \n- se poate deriva in functie de orice litera mica a alfabetului; \n(o singura variabila restul sunt constante)\n- se poate deriva de pana la 9 ori;\n- butonul de salvare in fisier salveaza istoricul functiilor introduse\nin urma unei sesiuni; \n \nPROIECT REALIZAT DE STUDENTII : \nIOANA PETRARIU\nTUDOR - CONSTANTIN PRICOP\n", font, 25);
                    textinfos.setFillColor(Color::White);
                    textinfos.setPosition(60, 60);

                    RenderWindow infos(VideoMode(800, 600), "Info");
                    while (infos.isOpen())
                    {
                        Event event;
                        while (infos.pollEvent(event))
                        {
                            if (event.type == Event::Closed)
                                infos.close();
                        }
                        infos.clear();

                        infos.draw(sprite);
                        infos.draw(casetainfos);
                        infos.draw(textinfos);

                        infos.display();

                    }
                }
                if (isSpriteHover(casetafont.getGlobalBounds(), mp))
                {
                    if (fontul == 0)
                    {
                        font.loadFromFile("AlexBrush-Regular.ttf");
                        fontul = 1;
                    }
                    else
                    {
                        font.loadFromFile("Antaro.ttf");
                        fontul = 0;
                    }
                }
                if (isSpriteHover(casetasave.getGlobalBounds(), mp))
                {
                    char siraux[NMAX] = { 0 };
                    stringtochar(sirfunctie, siraux);
                    fprintf(fout, "Functia %s ", siraux);

                    stringtochar(sirfde, siraux);
                    fprintf(fout, "d%s ", siraux);

                    stringtochar(sirori, siraux);
                    if(siraux[0]=='1')
                        fprintf(fout, "derivata o data:");
                    else
                        fprintf(fout, "derivata de %s ori:", siraux);
                    
                    stringtochar(siroutput, siraux);
                    fprintf(fout,"\n%s\n\n", siraux);
                }
                if (isSpriteHover(spritero.getGlobalBounds(), mp))  // schimbare limba in romana
                {
                    limba = 0;
                }
                if (isSpriteHover(spriteen.getGlobalBounds(), mp))  // schimbare limba in engleza
                {
                    limba = 1;
                }
            }
            if (event.type == Event::TextEntered)
            {
                if (isSpriteHover(introdu.getGlobalBounds(), mp))
                {
                    if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        if (userinput.getSize() > 0)
                        {
                            userinput.erase(userinput.getSize() - 1, 1);
                            usertext.setString(userinput);
                        }
                    }
                    else if (event.text.unicode < 128)
                    {
                        userinput += event.text.unicode;
                        usertext.setString(userinput);
                    }
                }
                if (isSpriteHover(functiede.getGlobalBounds(), mp))
                {
                    if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        if (userinputfde.getSize() > 0)
                        {
                            userinputfde.erase(userinputfde.getSize() - 1, 1);
                            usertextfde.setString(userinputfde);
                        }
                    }
                    else if (event.text.unicode < 128)
                    {
                        userinputfde += event.text.unicode;
                        usertextfde.setString(userinputfde);
                    }
                }
                if (isSpriteHover(decateori.getGlobalBounds(), mp))
                {
                    if (Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        if (userinputori.getSize() > 0)
                        {
                            userinputori.erase(userinputori.getSize() - 1, 1);
                            usertextori.setString(userinputori);
                        }
                    }
                    else if (event.text.unicode < 128)
                    {
                        userinputori += event.text.unicode;
                        usertextori.setString(userinputori);
                    }
                }
            }
            if (event.type == Event::Closed)
                window.close();

        }

        window.clear();

        window.draw(sprite);
        window.draw(spritero);
        window.draw(spriteen);

        window.draw(introdu);
        window.draw(functiede);
        window.draw(decateori);
        window.draw(casetaderivare);
        window.draw(casetainfo);
        window.draw(casetasave);
        window.draw(casetaarbore);
        window.draw(casetafont);

        if (limba == 0) ///romana
        {
            window.draw(textintrodu);
            window.draw(textfunctiede);
            window.draw(textdecateori);
            window.draw(textcasetaderivare);
            window.draw(textcasetainfo);
            window.draw(textcasetaarbore);
            window.draw(textcasetasave);
            window.draw(textcasetafont);
        }
        if (limba == 1) ///engleza
        {
            window.draw(entextintrodu);
            window.draw(entextfunctiede);
            window.draw(entextdecateori);
            window.draw(entextcasetaderivare);
            window.draw(entextcasetainfo);
            window.draw(entextcasetaarbore);
            window.draw(entextcasetasave);
            window.draw(entextcasetafont);
        }


        window.draw(usertext);
        window.draw(usertextfde);
        window.draw(usertextori);

        if (randuri == 1)
        {
            window.draw(usertextoutput1);
        }
        else if (randuri == 2)
        {
            window.draw(usertextoutput1);
            window.draw(usertextoutput2);
        }
        else
        {
            window.draw(usertextoutput1);
            window.draw(usertextoutput2);
            window.draw(usertextoutput3);
        }

        window.display();
    }
}

string numberToString(float numar)
{
    bool ok = 0;
    string nr;
    char invers[NMAX] = { 0 };
    char caracter;
    int contor = 0;
    if (numar < 0)
    {
        nr += "(-";
        numar = -numar;
        ok = 1;
    }
    int intreg = numar;
    numar -= intreg;
    if (intreg == 0)
    {
        nr += "0";
    }
    else
    {
        while (intreg > 0)
        {
            caracter = intreg % 10+'0';
            invers[contor++] = caracter;
            intreg /= 10;
        }
        invers[contor] = NULL;
        _strrev(invers);
        nr.append(invers);
    }
    
    if (numar != 0)
    {
        nr += '.';
        while (numar > 0.0001)///precizie 3 zecimale!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            numar *= 10;
            intreg = numar;
            nr += intreg + '0';
            numar -= intreg;
        }
    }

    if (ok)
    {
        nr += ")";
    }
    return nr;
}

void stringtochar(string str, char Sir[])
{
    int i;
    for ( i = 0; str[i] != NULL; ++i)
    {
        Sir[i] = str[i];
    }
    Sir[i] = NULL;
}

void citire(char s[]) ///citirea din fisier
{
    fgets(s, NMAX, fin);
    fscanf(fin, "%c", &variabila_derivare);
} 

void derivare_functie(char s[], int ordin)
{
    char v[NMAX][LMAX];
    int lungime = 0;
    nod* a = new nod;
    queue < string > coada;
    string sir;

    vectorizare(s, v, lungime);            ///transforma sirul s primit ca parametru intr-un vector de tokenuri
    coada = postfix(v, lungime);           ///aranjeaza in ordinea postfixata tokenurile
    sir = parantezare(coada);              ///parantezeaza forma postfixata pentru arborizarea functiei intr-un sir de caractere
    sir.copy(s, NMAX);
    s[sir.length()] = 0;
    vectorizare(s, v, lungime);            ///transforma sirul parantezat in tokenuri pentru arborizare

    a = arborizare(v, 0);                  ///face arborele asociat functiei

    for (int i = 1; i <= ordin; i++)       ///deriveaza si simplifica arborele de cate ori este precizat
    {
        a = derivare(a);
        simplificare(a);
    }

    arbore_output=copiere(a);              ///copiaza arborele pentru a fi afisat
    output(a);                             ///transforma din arbore in functie 
}


void output(arb a)   ///punem intr-un string
{
    if (a != NULL)
    {
        if (a->tip == 1)
        {
            siroutput.append(numberToString(a->info));
        }
        if (a->tip == 0)
        {
            if (a->inf[0] >= 'a' && a->inf[0] <= 'z' && a->inf[1] == NULL)
                siroutput.append(a->inf);
            else if (functie(a->inf))
            {
                siroutput.append(a->inf);
                output(a->st);
            }
            else if (operand(a->inf[0]))
            {
                if (a->prev == NULL || (priorit(a->inf) >= priorit(a->prev->inf) && !(a->inf[0]=='*' && a->prev->inf[0]=='/' && a->prev->dr==a)))  /// !!!
                {
                    output(a->st);
                    siroutput.append(a->inf);
                    output(a->dr);
                }
                else
                {
                    siroutput.append("(");
                    output(a->st);
                    siroutput.append(a->inf);
                    output(a->dr);
                    siroutput.append(")");
                }
            }
        }
    }
}

queue <string> postfix(char v[NMAX][LMAX], int lungime)
{
    stack < string > stiva;
    queue < string > coada;
    int i = 0;

    while (i <= lungime) 
    {
        if (functie(v[i]) || (operand(v[i][0]) && v[i][1] == NULL) || v[i][0] == '(' || v[i][0] == ')')
        {
            if (stiva.empty())
            {
                stiva.push(v[i]);
            }
            else
            {
                if (v[i][0] == '(')
                    stiva.push(v[i]);
                else if (v[i][0] == ')')
                {
                    while (stiva.top() != "(")
                    {
                        coada.push(stiva.top());
                        stiva.pop();
                    }
                    stiva.pop();
                }
                else if (priorit(v[i]) >= priorit(stiva.top()) || stiva.top() == "(")
                    stiva.push(v[i]);
                else
                {
                    while (!stiva.empty() && priorit(v[i]) < priorit(stiva.top())  && stiva.top() != "(")
                    {
                        coada.push(stiva.top());
                        stiva.pop();
                    }
                    stiva.push(v[i]);
                }
            }
        }
        else
        {
            coada.push(v[i]);
        }
        i++;
    }
    
    while (!stiva.empty())
    {
        coada.push(stiva.top());
        stiva.pop();
    }

    /*while (!coada.empty())
    {
        cout << coada.front() << " ";
        coada.pop();
    }*/

    return coada;
}

void afisare_stiva(stack <string> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl << endl;
}

string parantezare(queue <string> coada)
{
    stack <string> stiva;
    string ec, op1, op2;
    while (!coada.empty())
    {
        if (functie(coada.front()))
        {
            op1 = stiva.top();
            stiva.pop();
            ec = coada.front();
            coada.pop();
            ec.append(op1);
            stiva.push(ec);
            op1.clear();
            ec.clear();
        }
        else if (operand(coada.front()))
        {
            op1 = stiva.top();
            stiva.pop();
            op2 = stiva.top();
            stiva.pop();
            ec = "(";
            ec.append(op2);
            ec.append(coada.front());
            coada.pop();
            ec.append(op1);
            ec.append(")");
            stiva.push(ec);
            op1.clear();
            op2.clear();
            ec.clear();
        }
        else {
            stiva.push(coada.front());
            coada.pop();
        }
    }
    return stiva.top();
}

int priorit(string c)    ///stabileste prioritatea operatorilor
{
    if (c[0] == '+' || c[0] == '-')
        return 0;
    if (c[0] == '*' || c[0] == '/')
        return 1;
    if (c[0] == '^' || c[1] == 'q')
        return 2;
    if (c[0] == 's' || c[0] == 'c' || c[0] == 't' || c[0] == 'l')
        return 3;
}

bool ok; /// flag pentru simplificare;
void simplificare(arb& a)
{
    /// bubble simplificarea
    do
    {
        ok = 0;
        a->prev = NULL;
        previous(a);
        a = simplificare_partiala(a);
    } while (ok == 1);
}

arb simplificare_partiala(arb a)
{
    if (a == NULL) return NULL;
    if (a != NULL)
    {
        if (a->tip == 0)
        {
            if (a->inf[0] == '*')
            {
                if (a->st->tip == 1 && a->dr->tip == 1)  ///nr1*nr2
                {
                    a->tip = 1;
                    a->inf[0] = NULL;
                    a->info = a->st->info * a->dr->info;
                    delete a->st;
                    delete a->dr;
                    a->st = NULL;
                    a->dr = NULL;

                    ok = 1;
                }
                if (ok==0 && a->st->tip == 1)
                {
                    if (a->st->info == 0)    /// 0*u
                    {
                        a->tip = 1;
                        a->info = 0;
                        delete(a->st);
                        a->st = NULL;
                        a->dr = NULL;
                        ok = 1;
                    }
                    else if (a->st->info == 1)   ///   1*u
                    {
                        delete(a->st);
                        a->st = NULL;
                        nod* r, * p;
                        r = a->dr;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
                if (ok == 0 && a->dr->tip == 1)
                {
                    if (a->dr->info == 0)    ///  u*0
                    {
                        a->tip = 1;
                        a->info = 0;
                        delete(a->dr);
                        a->dr = NULL;
                        a->st = NULL;
                        ok = 1;
                    }
                    else if (a->dr->info == 1)   ///  u*1
                    {
                        delete(a->dr);
                        a->dr = NULL;
                        nod* r, * p;
                        r = a->st;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
            }
            else if (a->inf[0] == '+')
            {
                if (a->st->tip == 1 && a->dr->tip == 1) ///nr1+nr2
                {
                    a->tip = 1;
                    a->inf[0] = NULL;
                    a->info = a->st->info + a->dr->info;
                    delete a->st;
                    delete a->dr;
                    a->st = NULL;
                    a->dr = NULL;

                    ok = 1;
                }
                if (ok==0 && a->st->tip == 1)     ///  0+u
                {
                    if (a->st->info == 0)
                    {
                        delete(a->st);
                        a->st = NULL;
                        nod* r, * p;
                        r = a->dr;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
                if (ok == 0 && a->dr->tip == 1)   /// u+0
                {
                    if (a->dr->info == 0)
                    {
                        delete(a->dr);
                        a->dr = NULL;
                        nod* r, * p;
                        r = a->st;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
            }
            else if (a->inf[0] == '-')
            {
                if (a->st->tip == 1 && a->dr->tip == 1) ///nr1-nr2
                {
                    a->tip = 1;
                    a->inf[0] = NULL;
                    a->info = a->st->info - a->dr->info;
                    delete a->st;
                    delete a->dr;
                    a->st = NULL;
                    a->dr = NULL;

                    ok = 1;
                }
                if (ok==0 && a->st->tip == 1)     ///  0-u
                {
                    if (a->st->info == 0)
                    {
                        a->inf[0] = '*';
                        a->st->info = -1;
                        ok = 1;
                    }
                }
                if (ok == 0 && a->dr->tip == 1)   /// u-0
                {
                    if (a->dr->info == 0)
                    {
                        delete(a->dr);
                        a->dr = NULL;
                        nod* r, * p;
                        r = a->st;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
            }
            else if (a->inf[0] == '/')
            {
                if (a->st->tip == 1 && a->dr->tip == 1 && a->dr->info!=0) ///nr1/nr2
                {
                    a->tip = 1;
                    a->inf[0] = NULL;
                    a->info = a->st->info / a->dr->info;
                    delete a->st;
                    delete a->dr;
                    a->st = NULL;
                    a->dr = NULL;

                    ok = 1;
                }
                if (ok==0 && a->st->tip == 1)      /// 0/u
                {
                    if (a->st->info == 0)
                    {
                        a->tip = 1;
                        a->info = 0;
                        delete(a->st);
                        a->st = NULL;
                        a->dr = NULL;
                        ok = 1;
                    }
                }
                if (ok == 0 && a->dr->tip == 1)    ///   u/1
                {
                    if (a->dr->info == 1)
                    {
                        delete(a->dr);
                        a->dr = NULL;
                        nod* r, * p;
                        r = a->st;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                }
            }
            else if (a->inf[0] == '^')
            {
                if (a->st->tip == 1)
                {
                    if (a->st->info == 0)     ///  0^u
                    {
                        a->tip = 1;
                        a->info = 0;
                        delete(a->st);
                        a->st = NULL;
                        a->dr = NULL;
                        ok = 1;
                    }
                    else if (a->st->info == 1)   ///  1^u
                    {
                        a->tip = 1;
                        a->info = 1;
                        delete(a->st);
                        a->st = NULL;
                        a->dr = NULL;
                        ok = 1;
                    }
                }
                if (ok == 0 && a->dr->tip == 1)
                {
                    if (a->dr->info == 1)   ///  u^1
                    {
                        delete(a->dr);
                        a->dr = NULL;
                        nod* r, * p;
                        r = a->st;
                        p = a->prev;
                        if (p == NULL)
                        {
                            delete(a);
                            a = r;
                            a->prev = NULL;
                        }
                        else if (p->st == a)
                        {
                            delete(a);
                            p->st = r;
                            r->prev = p;
                            a = r;
                        }
                        else if (p->dr == a)
                        {
                            delete(a);
                            p->dr = r;
                            r->prev = p;
                            a = r;
                        }
                        ok = 1;
                    }
                    else if (a->dr->info == 0)  ///  u^0
                    {
                        a->tip = 1;
                        a->info = 1;
                        delete(a->dr);
                        a->dr = NULL;
                        a->st = NULL;
                        ok = 1;
                    }
                }
            }
        }
        a->st = simplificare_partiala(a->st);
        a->dr = simplificare_partiala(a->dr);
        return a;
    }
}

void previous(arb& a) ///stabileste nodul parinte
{
    if (a->st != NULL)
    {
        a->st->prev = a;
        previous(a->st);
    }
    if (a->dr != NULL)
    {
        a->dr->prev = a;
        previous(a->dr);
    }
}

///pentru ca avem ( in sirul initial se va apela arborizare() )
arb  arborizare(char v[NMAX][LMAX], int poz)
{
    if (v[poz][0] == NULL)
        return NULL;
    nod* rad = new nod;
    if (v[poz][0] >= '0' && v[poz][0] <= '9')
    {
        rad->tip = 1;
        rad->info = stringToNumber(v[poz]);
        rad->st = NULL;
        rad->dr = NULL;
    }
    else if (v[poz][0] == '-' && v[poz][1] >= '0' && v[poz][1] <= '9')
    {
        rad->tip = 1;
        rad->info = stringToNumber(v[poz]);
        rad->st = NULL;
        rad->dr = NULL;
    }
    else if (v[poz][0] == variabila_derivare && v[poz][1] == NULL)
    {
        rad->tip = 0;
        strcpy(rad->inf, v[poz]);
        rad->st = NULL;
        rad->dr = NULL;
    }
    else if ((v[poz][0] >= 'a' && v[poz][0] <= 'z') && v[poz][1] == NULL)
    {
        rad->tip = 0;
        strcpy(rad->inf, v[poz]);
        rad->st = NULL;
        rad->dr = NULL;
    }
    else if (v[poz][0] == 's' || v[poz][0] == 'c' || v[poz][0] == 't' || v[poz][0] == 'l')
    {
        rad->tip = 0;
        strcpy(rad->inf, v[poz]);
        rad->st = arborizare(v, poz + 1);
        rad->dr = NULL;
    }
    else if (v[poz][0] == '(')
    {
        rad->tip = 0;
        rad->st = arborizare(v, poz + 1);
        int paranteze = 0, noduri_stanga = poz + 1;
        if (v[poz + 1][0] == 's' || v[poz + 1][0] == 'c' || v[poz + 1][0] == 't' || v[poz + 1][0] == 'l') noduri_stanga++;
        do
        {
            if (v[noduri_stanga][0] == '(')
                paranteze++;
            else if (v[noduri_stanga][0] == ')')
                paranteze--;
            noduri_stanga++;
        } while (paranteze != 0);
        strcpy(rad->inf, v[noduri_stanga]);
        rad->dr = arborizare(v, noduri_stanga + 1);
    }
    return rad;
}

arb  copiere(arb a)  ///copiaza un subarbore
{
    if (a == NULL) return NULL;
    else
    {
        nod* p = new nod;
        strcpy(p->inf, a->inf);
        p->tip = a->tip;
        p->info = a->info;
        p->st = copiere(a->st);
        p->dr = copiere(a->dr);
        return p;
    }
}

arb  derivare(arb a)
{
    if (a->st == NULL)
    {
        if (a->tip == 1)
            a->info = 0;
        else if (a->inf[0] >= 'a' && a->inf[0] <= 'z' && a->inf[1] == NULL && a->inf[0] != variabila_derivare)
        {
            a->tip = 1;
            a->info = 0;
        }
        else if (a->inf[0] == variabila_derivare)
        {
            a->tip = 1;
            a->info = 1;
        }
    }
    else if (a->inf[0] == 's' && a->inf[1] == 'i')
    {
        strcpy(a->inf, "*");
        nod* u, * st, * p;
        u = copiere(a->st);
        st = a->st;
        p = new nod;
        p->tip = 0;
        strcpy(p->inf, "cos");
        a->st = p;
        p->st = st;
        p->dr = NULL;
        a->dr = derivare(u);
    }
    else if (a->inf[0] == 's' && a->inf[1] == 'q')
    {
        strcpy(a->inf, "/");
        nod * st, * f, * p, * q, * r;
        f = copiere(a->st);
        st = a->st;

        p = new nod;
        p->tip = 1;
        p->info = 2;
        p->st = NULL;
        p->dr = NULL;

        q = new nod;
        q->tip = 0;
        strcpy(q->inf, "sqrt");
        q->st = st;
        q->dr = NULL;

        r = new nod;
        r->tip = 0;
        strcpy(r->inf, "*");
        r->st = p;
        r->dr = q;

        a->dr = r;
        a->st = derivare(f);

    }
    else if (a->inf[0] == 'c' && a->inf[1] == 'o')
    {
        strcpy(a->inf, "-");
        nod* u, * st, * p, * q, * r;
        u = copiere(a->st);
        st = a->st;
        p = new nod;
        p->tip = 1;
        p->info = 0;
        p->st = NULL;
        p->dr = NULL;
        a->st = p;
        q = new nod;
        q->tip = 0;
        strcpy(q->inf, "*");
        r = new nod;
        r->tip = 0;
        strcpy(r->inf, "sin");
        r->st = st;
        r->dr = NULL;
        q->st = r;
        q->dr = derivare(u);
        a->dr = q;
    }
    else if (a->inf[0] == 't' && a->inf[1] == 'g')
    {
        nod* st, * u, * p;
        st = a->st;
        u = copiere(a->st);
        strcpy(a->inf, "*");

        p = new nod;
        strcpy(p->inf, "+");
        p->tip = 0;
        a->st = p;

        p = new nod;
        p->info = 1;
        p->tip = 1;
        p->st = NULL;
        p->dr = NULL;
        a->st->dr = p;

        p = new nod;
        strcpy(p->inf, "^");
        p->tip = 0;
        a->st->st = p;

        p = new nod;
        p->info = 2;
        p->tip = 1;
        p->st = NULL;
        p->dr = NULL;
        a->st->st->dr = p;

        p = new nod;
        strcpy(p->inf, "tg");
        p->tip = 0;
        p->dr = NULL;
        p->st = st;
        a->st->st->st = p;

        a->dr = derivare(u);
    }
    else if (a->inf[0] == 'c' && a->inf[1] == 't')
    {
        nod* st, * u, * p;
        st = a->st;
        u = copiere(a->st);
        strcpy(a->inf, "*");

        p = new nod;
        strcpy(p->inf, "-");
        p->tip = 0;
        a->st = p;

        p = new nod;
        p->info = -1;
        p->tip = 1;
        p->st = NULL;
        p->dr = NULL;
        a->st->st = p;

        p = new nod;
        strcpy(p->inf, "^");
        p->tip = 0;
        a->st->dr = p;

        p = new nod;
        p->info = 2;
        p->tip = 1;
        p->st = NULL;
        p->dr = NULL;
        a->st->dr->dr = p;

        p = new nod;
        strcpy(p->inf, "ctg");
        p->tip = 0;
        p->dr = NULL;
        p->st = st;
        a->st->dr->st = p;

        a->dr = derivare(u);
    }
    else if (a->inf[0] == 'l' && a->inf[1] == 'n')
    {
        strcpy(a->inf, "/");
        nod* u, * st;
        u = copiere(a->st);
        st = a->st;
        a->dr = st;
        a->st = derivare(u);
    }
    else if (a->inf[0] == '+' || a->inf[0] == '-')
    {
        a->st = derivare(a->st);
        a->dr = derivare(a->dr);
    }
    else if (a->inf[0] == '*')
    {
        a->inf[0] = '+';
        /// copiem subarborele stang si cel drept ----- nod* copiere(nod *a)

        nod* st, * dr, * f, * g;   /// f si g se folosesc pentru derivare
        st = a->st;
        dr = a->dr;
        f = copiere(a->st);
        g = copiere(a->dr);

        nod* p, * q;
        p = new nod;
        q = new nod;

        p->inf[0] = '*';
        p->tip = 0;
        p->inf[1] = NULL;
        q->inf[0] = '*';
        q->tip = 0;
        q->inf[1] = NULL;

        a->st = p;
        a->dr = q;

        p->st = derivare(f);
        p->dr = dr;

        q->st = st;
        q->dr = derivare(g);
    }
    else if (a->inf[0] == '/')
    {
        /// copiem subarborele stang si cel drept ----- nod* copiere(nod *a)
        /// f si g se folosesc pentru derivare

        nod* st, * dr, * f, * g, * g2, * r, * r1;
        st = a->st;
        dr = a->dr;
        f = copiere(a->st);
        g = copiere(a->dr);
        g2 = copiere(a->dr);

        r = new nod;
        strcpy(r->inf, "-");
        r->tip = 0;

        a->st = r;

        nod* p, * q;
        p = new nod;
        q = new nod;

        p->inf[0] = '*';
        p->tip = 0;
        p->inf[1] = NULL;
        q->inf[0] = '*';
        q->tip = 0;
        q->inf[1] = NULL;

        r->st = p;
        r->dr = q;

        p->st = derivare(f);
        p->dr = dr;

        q->st = st;
        q->dr = derivare(g);

        nod* r2;
        r2 = new nod;
        r2->tip = 1;
        r2->info = 2;
        r2->st = NULL;
        r2->dr = NULL;

        r1 = new nod;
        r1->inf[0] = '^';
        r1->tip = 0;
        r1->inf[1] = NULL;
        r1->st = g2;
        r1->dr = r2;

        a->dr = r1;
    }
    else if (a->inf[0] == '^')
    {
        if (a->dr->tip == 1)
        {
            a->inf[0] = '*';

            nod* st, * dr, * f, * p, * q, * r;
            st = a->st;
            dr = a->dr;
            f = copiere(a->st);

            p = new nod;
            p->tip = 0;
            strcpy(p->inf, "*");
            p->st = dr;
            p->dr = derivare(f);

            a->st = p;

            r = new nod;
            r->tip = 1;
            r->info = dr->info - 1;
            r->st = NULL;
            r->dr = NULL;
            
            q = new nod;
            q->tip = 0;
            strcpy(q->inf, "^");
            q->st = st;
            q->dr = r;

            a->dr = q;
        }
        else
        {
            a->inf[0] = '*';

            nod* st, * dr, * f, * g, * p, * q, * r;
            st = a->st;
            dr = a->dr;
            f = copiere(a->st);
            g = copiere(a->dr);

            p = new nod;
            p->tip = 0;
            strcpy(p->inf, "^");
            p->st = st;
            p->dr = dr;
            a->dr = p;

            r = new nod;
            r->tip = 0;
            strcpy(r->inf, "*");
            r->st = g;
            q = new nod;
            q->tip = 0;
            strcpy(q->inf, "ln");
            q->st = f;
            q->dr = NULL;
            r->dr = q;

            a->st = derivare(r);
        }
    }
    return a;
}

float stringToNumber(char sir[])
{
    float numar = 0;
    int i = 0;
    bool semn = 0; /// 0-pozitiv; 1-negativ;
    if (sir[0] == '-')
    {
        semn = 1;
        i++;
    }
    while (i < strlen(sir) && sir[i] != '.')
    {
        numar = numar * 10 + (int)(sir[i] - '0');
        i++;
    }
    if (sir[i] == '.')
    {
        i++;
        float fractionar = 0;
        int pow = 1;
        while (i < strlen(sir))
        {
            fractionar = fractionar * 10 + (int)(sir[i] - '0');
            i++;
            pow = pow * 10;
        }
        numar = numar + (float)(fractionar) / pow;
    }
    if (semn == 1)
        numar = -numar;
    return numar;
}

void inordine(arb a) ///afisare in inordine in fisier
{
    if (a != NULL)
    {
        inordine(a->st);
        if (a->tip == 0)
            fprintf(fout, "%s ", a->inf);
        else fprintf(fout, "%f ", a->info);
        inordine(a->dr);
    }
}

void vectorizare(char s[], char v[NMAX][LMAX], int& k) 
{
    k = 0;
    int n = strlen(s);
    int i = 0;
    while (i < n)
        testare(s, v, i, k);
    k--;

    /// afisare token-uri
    /* cout << endl;
     for(i=0;i<=k;i++)
         cout<<v[i]<<" ";
     cout << endl;*/
}

void testare(char s[], char v[NMAX][LMAX], int& i, int& k) ///functie din vectorizare (pozitia i din sir)
{
    if (i == 0 && s[i] == '-')
    {
         int contor = 0;
         v[k][contor++] = '-';
         i++;
         while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
         {
             v[k][contor] = s[i];
             contor++;
             i++;
         }
         v[k][contor] = NULL;
    }
    else if (s[i] == '(' && s[i + 1] == '-')
    {
        int contor = 0;
        v[k][contor++] = '-';
        i = i + 2;
        while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            v[k][contor] = s[i];
            contor++;
            i++;
        }
        v[k][contor] = NULL;

        if (s[i] == ')')
        {
            i++;
        }
        else
        {
            strcpy(v[k + 1], v[k]);
            strcpy(v[k], "(");
            k++;
        }
    }
    else if (s[i] >= '0' && s[i] <= '9')
    {
        int contor = 0;
        while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            v[k][contor] = s[i];
            contor++;
            i++;
        }
        v[k][contor] = NULL;

        if (!operand(s[i]) && s[i] != ')' && s[i]!=NULL) /// 5x == 5*x
        {
            k++;
            v[k][0] = '*';
            v[k][1] = NULL;
        }
    }
    else if (operand(s[i]) || s[i] == '(' || s[i] == ')' || (s[i] >= 'a' && s[i] <= 'z' && (s[i + 1] < 'a' || s[i + 1]>'z')))
    {
        v[k][0] = s[i];
        v[k][1] = NULL;
        i++;
    }
    else if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] >= 'a' && s[i + 1] <= 'z')) /// daca avem 2 caractere alaturate at avem o functie
    {
        if (s[i] == 's' && s[i+1] == 'i')
        {
            strcpy(v[k], "sin");
            i += 3;
        }
        else if (s[i] == 's' && s[i + 1] == 'q')
        {
            strcpy(v[k], "sqrt");
            i += 4;
        }
        else if (s[i] == 'c' && s[i + 1] == 'o')
        {
            strcpy(v[k], "cos");
            i += 3;
        }
        else if (s[i] == 'c' && s[i + 1] == 't')
        {
            strcpy(v[k], "ctg");
            i += 3;
        }
        else if (s[i] == 't' && s[i + 1] == 'g')
        {
            strcpy(v[k], "tg");
            i += 2;
        }
        else if (s[i] == 'l' && s[i + 1] == 'n')
        {
            strcpy(v[k], "ln");
            i += 2;
        }
    }
    else i++;

    k++;
}

bool operand(char c)  ///verifica daca este operand
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    return 0;
}

bool operand(string c)
{
    if ((c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/' || c[0] == '^') && c[1]==NULL)
        return 1;
    return 0;
}

bool functie(string c) ///verifica daca este functie
{
    if ((c[0] == 's' || c[0] == 'c' || c[0] == 't' || c[0] == 'l') && (c[1] >= 'a' && c[1] <= 'z'))
        return 1;
    return 0;
}

