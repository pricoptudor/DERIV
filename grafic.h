#pragma once

#include <queue>
#include <stack>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define wmax 1700
#define hmax 1000
#define nmax 10000
#define raza_std 30
#define cifre_std 4
#define NMAX 300
#define LMAX 7

using namespace std;
using namespace sf;

struct nod
{
    bool tip; /// 0-caracter 1-numar real
    char inf[LMAX]; ///se pastreaza functie operand sau variabila
    float info;  ///se pastreaza numarul
    nod* st;
    nod* dr;
    nod* prev;
};
typedef nod* arb;

struct Punct
{
    int x;
    int y;
};

char variabila_derivare;
string siroutput;
arb arbore_output;

Punct coord_elem[nmax];
int raze[nmax];
int elem[nmax];
int centru_h, centru_w;
RenderWindow window_arb;

/// ////////////

void draw_tree(arb a, int contor, int nivel, int transport);
void draw_node(int tip, float val, char sir[], int contor, int niv, int col);
void convertToString(float nr, char s[]);
int nrCol(arb a);
int nrNiv(arb a);
void afisare(arb a);
void fereastra(arb a);
bool isSpriteHover(FloatRect forma, Vector2f mp);

/// ////////////

bool isSpriteHover(FloatRect forma, Vector2f mp) ///verifica daca mouse-ul este peste o caseta
{
    if (forma.contains(mp))
    {
        return true;
    }
    return false;
}

void fereastra(arb a) ///construieste fereastra pentru afisarea arborelui
{
    window_arb.create(VideoMode(wmax, hmax), "Arbore derivata");
    while (window_arb.isOpen())
    {
        Event event;
        while (window_arb.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window_arb.close();
        }
        window_arb.clear();

        afisare(a);

        window_arb.display();
    }
}

void afisare(arb a)
{
    centru_w = wmax / nrCol(a);
    centru_h = hmax / nrNiv(a);

    draw_tree(a, 1, 1, 0);
}

int nrNiv(arb a)
{
    if (a == NULL)
        return 0;

    return 1 + max(nrNiv(a->st), nrNiv(a->dr));
}

int nrCol(arb a)
{
    if (a == NULL)
        return 0;

    return 1 + nrCol(a->st) + nrCol(a->dr);
}

void convertToString(float nr, char s[])  
{
    int intreg = (int)nr;
    float fractionar = nr - (float)intreg;
    if (fractionar < 0)
        fractionar = -fractionar;

    _itoa_s(intreg, s, 10, 10);

    if ((int)fractionar != (float)fractionar && fractionar > 0.0001)
    {
        while ((int)fractionar != (float)fractionar && (fractionar-(int)fractionar) > 0.0001)
            fractionar *= 10;
        char aux[10];
        _itoa_s(fractionar, aux, 10, 10);
        strcat_s(s, 10, ".");
        strcat_s(s, 10, aux);
    }
}

void draw_node(int tip, float val, char sir[], int contor, int niv, int col)
{
    int cx, cy, r;
    cx = (col - 1) * centru_w + centru_w / 2;
    cy = (niv - 1) * centru_h + centru_h / 2;
    r = raza_std;

    coord_elem[contor].x = cx;
    coord_elem[contor].y = cy;
    raze[contor] = r;

    CircleShape circle;
    circle.setPosition(Vector2f(cx - r, cy - r));
    circle.setRadius(r);
    circle.setOutlineColor(Color::White);
    circle.setFillColor(Color::Green);
    window_arb.draw(circle);

    if (contor != 1)
    {
        int lx1, ly1, lx2, ly2;
        lx1 = cx;
        ly1 = cy - r;
        lx2 = coord_elem[contor / 2].x;
        ly2 = coord_elem[contor / 2].y + raze[contor / 2];

        VertexArray lines(LinesStrip, 2);
        lines[0].position = Vector2f(lx1, ly1);
        lines[1].position = Vector2f(lx2, ly2);
        window_arb.draw(lines);
    }

    Font font;
    if (!font.loadFromFile("Antaro.ttf"))
    {
        cout << "error loading font\n";
    }

    if (tip == 1)
    {
        char s[20] = { 0 };
        convertToString(val, s);
        int dif1, dif2=15;
        dif1 = strlen(sir) * 3;
        Text text;
        text.setFont(font);
        text.setString(s);
        text.setCharacterSize(30);
        text.setFillColor(Color::Red);
        text.setStyle(Text::Bold);
        text.setPosition(cx - dif1, cy - dif2);
        window_arb.draw(text);
    }
    else if (tip == 0)
    {
        int dif1, dif2=15;
        dif1 = strlen(sir) * 6;
        Text text;
        text.setFont(font);
        text.setString(sir);
        text.setCharacterSize(30);
        text.setFillColor(Color::Red);
        text.setStyle(Text::Bold);
        text.setPosition(cx - dif1, cy - dif2);
        window_arb.draw(text);
    }
}

void draw_tree(arb a, int contor, int nivel, int transport)
{
    if (a != NULL)
    {
        draw_node(a->tip, a->info, a->inf, contor, nivel, 1 + nrCol(a->st) + transport);

        draw_tree(a->st, contor * 2, nivel + 1, transport);
        draw_tree(a->dr, contor * 2 + 1, nivel + 1, transport + 1 + nrCol(a->st));
    }
}
