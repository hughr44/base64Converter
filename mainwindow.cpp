#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<math.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(button_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(button_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int *decToBinary(int num){
    int temp = num;
    static int bin[8];
    int val = 128;
    for(int i=0; i<8; ++i){
        if(temp < val){
            bin[i] = 0;
        }
        else{
            bin[i] = 1;
            temp -= val;
        }
        val = val / 2;
    }
    return bin;
}

int *b64ToBinary(int num){
    int temp = num;
    static int bin[6];
    int val = 32;
    for(int i=0; i<6; ++i){
        if(temp < val){
            bin[i] = 0;
        }
        else{
            bin[i] = 1;
            temp -= val;
        }
        val = val / 2;
    }
    return bin;
}

int binaryToVal(int *pattern, int startInd, int numBits){
    int temp = pow(2, (numBits - 1));
    int val = 0;
    for(int i=0; i<numBits; ++i){
        if(pattern[startInd + i] == 1) val += temp;
        temp = temp / 2;
    }
    return val;
}

int asciiValtoB64Val(int num)
{
    int newVal;
    switch(num){
        case 65: newVal = 0; break;
        case 66: newVal = 1; break;
        case 67: newVal = 2; break;
        case 68: newVal = 3; break;
        case 69: newVal = 4; break;
        case 70: newVal = 5; break;
        case 71: newVal = 6; break;
        case 72: newVal = 7; break;
        case 73: newVal = 8; break;
        case 74: newVal = 9; break;
        case 75: newVal = 10; break;
        case 76: newVal = 11; break;
        case 77: newVal = 12; break;
        case 78: newVal = 13; break;
        case 79: newVal = 14; break;
        case 80: newVal = 15; break;
        case 81: newVal = 16; break;
        case 82: newVal = 17; break;
        case 83: newVal = 18; break;
        case 84: newVal = 19; break;
        case 85: newVal = 20; break;
        case 86: newVal = 21; break;
        case 87: newVal = 22; break;
        case 88: newVal = 23; break;
        case 89: newVal = 24; break;
        case 90: newVal = 25; break;
        case 97: newVal = 26; break;
        case 98: newVal = 27; break;
        case 99: newVal = 28; break;
        case 100: newVal = 29; break;
        case 101: newVal = 30; break;
        case 102: newVal = 31; break;
        case 103: newVal = 32; break;
        case 104: newVal = 33; break;
        case 105: newVal = 34; break;
        case 106: newVal = 35; break;
        case 107: newVal = 36; break;
        case 108: newVal = 37; break;
        case 109: newVal = 38; break;
        case 110: newVal = 39; break;
        case 111: newVal = 40; break;
        case 112: newVal = 41; break;
        case 113: newVal = 42; break;
        case 114: newVal = 43; break;
        case 115: newVal = 44; break;
        case 116: newVal = 45; break;
        case 117: newVal = 46; break;
        case 118: newVal = 47; break;
        case 119: newVal = 48; break;
        case 120: newVal = 49; break;
        case 121: newVal = 50; break;
        case 122: newVal = 51; break;
        case 48: newVal = 52; break;
        case 49: newVal = 53; break;
        case 50: newVal = 54; break;
        case 51: newVal = 55; break;
        case 52: newVal = 56; break;
        case 53: newVal = 57; break;
        case 54: newVal = 58; break;
        case 55: newVal = 59; break;
        case 56: newVal = 60; break;
        case 57: newVal = 61; break;
        case 43: newVal = 62; break;
        case 47: newVal = 63; break;
    }
    return newVal;
}

int b64ValtoAsciiVal(int num)
{
    int newVal;
    switch(num){
        case 0: newVal = 65; break;
        case 1: newVal = 66; break;
        case 2: newVal = 67; break;
        case 3: newVal = 68; break;
        case 4: newVal = 69; break;
        case 5: newVal = 70; break;
        case 6: newVal = 71; break;
        case 7: newVal = 72; break;
        case 8: newVal = 73; break;
        case 9: newVal = 74; break;
        case 10: newVal = 75; break;
        case 11: newVal = 76; break;
        case 12: newVal = 77; break;
        case 13: newVal = 78; break;
        case 14: newVal = 79; break;
        case 15: newVal = 80; break;
        case 16: newVal = 81; break;
        case 17: newVal = 82; break;
        case 18: newVal = 83; break;
        case 19: newVal = 84; break;
        case 20: newVal = 85; break;
        case 21: newVal = 86; break;
        case 22: newVal = 87; break;
        case 23: newVal = 88; break;
        case 24: newVal = 89; break;
        case 25: newVal = 90; break;
        case 26: newVal = 97; break;
        case 27: newVal = 98; break;
        case 28: newVal = 99; break;
        case 29: newVal = 100; break;
        case 30: newVal = 101; break;
        case 31: newVal = 102; break;
        case 32: newVal = 103; break;
        case 33: newVal = 104; break;
        case 34: newVal = 105; break;
        case 35: newVal = 106; break;
        case 36: newVal = 107; break;
        case 37: newVal = 108; break;
        case 38: newVal = 109; break;
        case 39: newVal = 110; break;
        case 40: newVal = 111; break;
        case 41: newVal = 112; break;
        case 42: newVal = 113; break;
        case 43: newVal = 114; break;
        case 44: newVal = 115; break;
        case 45: newVal = 116; break;
        case 46: newVal = 117; break;
        case 47: newVal = 118; break;
        case 48: newVal = 119; break;
        case 49: newVal = 120; break;
        case 50: newVal = 121; break;
        case 51: newVal = 122; break;
        case 52: newVal = 48; break;
        case 53: newVal = 49; break;
        case 54: newVal = 50; break;
        case 55: newVal = 51; break;
        case 56: newVal = 52; break;
        case 57: newVal = 53; break;
        case 58: newVal = 54; break;
        case 59: newVal = 55; break;
        case 60: newVal = 56; break;
        case 61: newVal = 57; break;
        case 62: newVal = 43; break;
        case 63: newVal = 47; break;
    }
    return newVal;
}

void MainWindow::button_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    QString newLabel;
    newLabel = button->text();

    QString inputBox;
    inputBox = ui->textEditIn->toPlainText();

    bool encode;
    if(newLabel == "Encode"){encode = true;}
    else{encode = false;}

    // find length of input
    int inputLength = 0;
    for(int i=0; inputBox[i]!='\0'; ++i){
        ++inputLength;
    }
    // padding length
    int paddingLen = 0;
    int totalNumBits = 0;
    int numCharsOut = 0;
    int bitsPerCharOut = 0;
    int bitsPerCharIn = 0;
    if(encode){
        if(inputLength % 3 == 2) paddingLen = 8;
        if(inputLength % 3 == 1) paddingLen = 16;
        totalNumBits = (8 * inputLength) + paddingLen;
        numCharsOut = totalNumBits / 6;
        bitsPerCharOut = 6;
        bitsPerCharIn = 8;
    }
    else{
        if(inputLength % 4 == 3) paddingLen = 6;
        if(inputLength % 4 == 2) paddingLen = 12;
        if(inputLength % 4 == 1) paddingLen = 18;
        totalNumBits = (6 * inputLength) + paddingLen;
        numCharsOut = totalNumBits / 8;
        bitsPerCharOut = 8;
        bitsPerCharIn = 6;
    }
    // create binary pattern
    qDebug() << inputLength;

    int binaryPattern[totalNumBits];
    int count = 0;
    int charVal = 0;
    QChar newChar;
    for(int i=0; inputBox[i]!='\0'; ++i){
        newChar = inputBox[i];
        if(encode){charVal = newChar.toLatin1();}
        else{
            charVal = newChar.toLatin1();
            charVal = asciiValtoB64Val(charVal);
        }
        int *p;
        if(encode){p = decToBinary(charVal);}
        else{p = b64ToBinary(charVal);}

        for(int i=0; i<bitsPerCharIn; ++i){
            binaryPattern[count] = *(p+i);
            ++count;
        }
    }
    // adding 0's for padding
    for(int i=0; i<paddingLen; ++i){
        binaryPattern[count] = 0;
        ++count;
    }

    // creating new values from binary pattern
    int tempVal = 0;
    int newVals[numCharsOut];
    for(int i=0; i<numCharsOut; ++i){
        tempVal = binaryToVal(binaryPattern, i*bitsPerCharOut, bitsPerCharOut);
        newVals[i] = tempVal;
    }

    QString newChars;
    for(int i=0; i<numCharsOut; ++i){
        if(encode){newChars[i] = b64ValtoAsciiVal(newVals[i]);}
        else{
            if(newVals[i] == 0){newChars[i] = ' ';}
            else{newChars[i] = newVals[i];}
        }
    }
    if(encode){
        if(paddingLen / 8 == 2){
            newChars[numCharsOut - 1] = '=';
            newChars[numCharsOut - 2] = '=';
        }
        if(paddingLen / 8 == 1){
            newChars[numCharsOut - 1] = '=';
        }
    }

    ui->textEditOut->setText(newLabel + "d: " + newChars);
    ui->textEditOut->setLineWrapMode(QTextEdit::WidgetWidth);
    ui->textEditOut->update();
    ui->textEditOut->repaint();
}

