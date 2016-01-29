// Prototypes
void display();
void zero(int digit);
void one(int digit);
void two(int digit);
void three(int digit);
void four(int digit);
void five(int digit);
void six(int digit);
void seven(int digit);
void eight(int digit);
void nine(int digit);
void sendtodisplay(char number, int digi);

// Define variables and constants
// Assign digits
#define dig4 A5 //Pin 6 on 4 dig
#define dig3 3 //Pin 8 on 4 dig
#define dig2 4 //Pin 9 on 4 dig
#define dig1 7 //Pin 12 on 4 dig

// Assign Segments
#define segE A0 //Pin 1 on 4 dig
#define segD A1 //Pin 2 on 4 dig
#define segH A2 //Pin 3 on 4 dig
#define segC A3 //Pin 4 on 4 dig
#define segG A4 //Pin 5 on 4 dig
#define segB 2 //Pin 7 on 4 dig
#define segF 5 //Pin 10 on 4 dig
#define segA 6 //Pin 11 on 4 dig

boolean onOff[4][8];

int pinmaped[13];

char DisplayBuffer[5];


void setup()
{
    // Assign pins to array
    pinmaped[1] = dig1;
    pinmaped[2] = dig2;
    pinmaped[3] = dig3;
    pinmaped[4] = dig4;
    pinmaped[5] = segA;
    pinmaped[6] = segB;
    pinmaped[7] = segC;
    pinmaped[8] = segD;
    pinmaped[9] = segE;
    pinmaped[10] = segF;
    pinmaped[11] = segG;
    pinmaped[12] = segH;
    
    //Set pins to output
    for(int i=1; i <= 12; i++)
    {
        pinMode(pinmaped[i], OUTPUT);
    }

    //Set booleen values
    //if true: the led voltage = max,
    //if false the led voltage = 0
    for(int i=0; i < 4; i++)
    {
        for(int j=0; j < 8; j++) onOff[i][j]=false;
    }
}


void loop()
{
    //Sync display to array
    display();
    
    // Get time since program started
    int time = millis();
    
    //Update boolen array if 0.1 seconds has passed
    if( (time%100) == 0)
    {
        uint32_t t2 = millis();
        sprintf(DisplayBuffer, "%4i", t2/100);
        sendtodisplay(DisplayBuffer[0], 0);
        sendtodisplay(DisplayBuffer[1], 1);
        sendtodisplay(DisplayBuffer[2], 2);
        sendtodisplay(DisplayBuffer[3], 3);
    }
    
    // Stability delay
    delay(1);
}


void sendtodisplay(char number, int digi)
{
    switch (int(number))
    {
        case 48:
            zero(digi);
            break;
        case 49:
            one(digi);
            break;
        case 50:
            two(digi);
            break;
        case 51:
            three(digi);
            break;
        case 52:
            four(digi);
            break;
        case 53:
            five(digi);
            break;
        case 54:
            six(digi);
            break;
        case 55:
            seven(digi);
            break;
        case 56:
            eight(digi);
            break;
        case 57:
            nine(digi);
        break;
    }
}


void display()
{
    //Digital display
    for(int i=0; i < 4; i++) //run on the digits
    {
        for(int j=5; j < 13; j++) {
            digitalWrite(pinmaped[j], false); //turn segment power off
        }
        digitalWrite(pinmaped[i+1], false); //turn digit power off
        
        //provide power to rest
        digitalWrite(pinmaped[1+(i+1)%4], true);
        digitalWrite(pinmaped[1+(i+2)%4], true);
        digitalWrite(pinmaped[1+(i+3)%4], true);
        
        for(int j=0; j < 8; j++)
        {
            //turn the specified segment from bool array
            digitalWrite(pinmaped[j+5], onOff[i][j]);
        }
    }
}


void zero(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=true;   //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=false;  //g
    onOff[digit][7]=false;  //h
    
}


void one(int digit)
{
    onOff[digit][0]=false;  //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=false;  //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=false;  //f
    onOff[digit][6]=false;  //g
    onOff[digit][7]=false;  //h
}


void two(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=false;  //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=true;   //e
    onOff[digit][5]=false;  //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void three(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=false;  //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void four(int digit)
{
    onOff[digit][0]=false;  //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=false;  //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void five(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=false;  //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void six(int digit)
{
    onOff[digit][0]=false;  //a
    onOff[digit][1]=false;  //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=true;   //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void seven(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=false;  //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=false;  //f
    onOff[digit][6]=false;  //g
    onOff[digit][7]=false;  //h
}


void eight(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=true;   //d
    onOff[digit][4]=true;   //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}


void nine(int digit)
{
    onOff[digit][0]=true;   //a
    onOff[digit][1]=true;   //b
    onOff[digit][2]=true;   //c
    onOff[digit][3]=false;  //d
    onOff[digit][4]=false;  //e
    onOff[digit][5]=true;   //f
    onOff[digit][6]=true;   //g
    onOff[digit][7]=false;  //h
}
