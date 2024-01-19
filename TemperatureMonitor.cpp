#include "mbed.h"

InterruptIn sw1(p15); // Fahrenheit. p15 is a PullUp
InterruptIn sw2(p26); // Celcius. p26 is a PullDown
AnalogIn vouttemp (p18); // Input from temp sensor to mbeds p18
BusOut display(p5,p6,p7,p8,p9,p10,p11,p12);
Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);
float vout;
float v_sum;
float v_avg;
float v_total_sample;
float convert_c;
float convert_f;
volatile int pressed = 1;
int floor_temp_f; // rounded to nearest whole number integer. This is rounded down.
int floor_temp_c; // rounded to nearest whole number integer. This is rounded down.
void fahrenheit_convert(void) {
    pc.printf("%f voltage \n\r", vout);
    convert_f = (((vout - 0.400) / (0.0195)) * (9.0/5.0)) + 32.0;
    pc.printf("%f degrees fahrenheit \n\r", convert_f);
    pc.printf("%f sum of 1000 samples \n\r", v_total_sample);
    pc.printf("%f is the avg of 1000 samples \n\r", v_avg);
    floor_temp_f = floor (convert_f);
    pc.printf("%d floor \n\r", floor_temp_f);
    int k =  (convert_f / 100);
    int i =  (convert_f / 10);
    int m = (int)convert_f % 10;
    
    if (vout < .68) {
        switch(12) {
            case 12: display = 0b01000000; break; // Negative - -
        }
        
        wait(1);
        
        switch(1) {
            case 1: display = 0b00000000; break;
        }
    }
    
    wait(.1);
    
    if (k != 0) {
        
        switch (k) {
            case 0: display = 0x3F; break; // Zero - 0
            case 1: display = 0x06; break; // One - 1
            case 2: display = 0x5B; break; // Two - 2
            case 3: display = 0x4F; break; // Three - 3
            case 4: display = 0x66; break; // Four - 4
            case 5: display = 0x6D; break; // Five - 5
            case 6: display = 0x7D; break; // Six - 6
            case 7: display = 0x07; break; // Seven - 7
            case 8: display = 0x7F; break; // Eight - 8
            case 9: display = 0x6F; break; // Nine - 9
        }
        
        wait(1);
    }
    
    switch (abs(i)) {
        case 0: display = 0x3F; break; // Zero - 0
        case 1: display = 0x06; break; // One - 1
        case 2: display = 0x5B; break; // Two - 2
        case 3: display = 0x4F; break; // Three - 3
        case 4: display = 0x66; break; // Four - 4
        case 5: display = 0x6D; break; // Five - 5
        case 6: display = 0x7D; break; // Six - 6
        case 7: display = 0x07; break; // Seven - 7
        case 8: display = 0x7F; break; // Eight - 8
        case 9: display = 0x6F; break; // Nine - 9
        case 10: display = 0b00111001; break; // C - Celcius
        case 11: display = 0b01110001; break; // F - Fahrenheit
        case 12: display = 0b01000000; break; // Negative - -
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
    
    switch (abs(m)) {
        case 0: display = 0x3F; break; // Zero - 0
        case 1: display = 0x06; break; // One - 1
        case 2: display = 0x5B; break; // Two - 2
        case 3: display = 0x4F; break; // Three - 3
        case 4: display = 0x66; break; // Four - 4
        case 5: display = 0x6D; break; // Five - 5
        case 6: display = 0x7D; break; // Six - 6
        case 7: display = 0x07; break; // Seven - 7
        case 8: display = 0x7F; break; // Eight - 8
        case 9: display = 0x6F; break; // Nine - 9
        case 10: display = 0b00111001; break; // C - Celcius
        case 11: display = 0b01110001; break; // F - Fahrenheit
        case 12: display = 0b01000000; break; // Negative - -
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
    
    switch (11) {
        case 11: display = 0b01110001; break; // F - Fahrenheit
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
    
}

void celcius_convert(void) {
    pc.printf("%f voltage \n\r", vout);
    convert_c = (vout - 0.400) / (0.0195);
    pc.printf("%f degrees celcius \n\r", convert_c);
    pc.printf("%f sum of 1000 samples \n\r", v_total_sample);
    pc.printf("%f is the avg of 1000 samples \n\r", v_avg);
    floor_temp_c = floor (convert_c);
    pc.printf("%d floor \n\r", floor_temp_c);
    int i =  (convert_c / 10);
    pc.printf("%d", i);
    int m = (int)convert_c % 10;
    
    if (vout < .4) {
        switch(12) {
            case 12: display = 0b01000000; break; // Negative - -
        }
        wait(1);
        
        switch(1) {
            case 1: display = 0b00000000; break;
        }
    }
    
    wait(.1);
    
    switch (abs(i)) {
            
        case 0: display = 0x3F; break; // Zero - 0
        case 1: display = 0x06; break; // One - 1
        case 2: display = 0x5B; break; // Two - 2
        case 3: display = 0x4F; break; // Three - 3
        case 4: display = 0x66; break; // Four - 4
        case 5: display = 0x6D; break; // Five - 5
        case 6: display = 0x7D; break; // Six - 6
        case 7: display = 0x07; break; // Seven - 7
        case 8: display = 0x7F; break; // Eight - 8
        case 9: display = 0x6F; break; // Nine - 9
            
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
    
    switch (abs(m)) {
            
        case 0: display = 0x3F; break; // Zero - 0
        case 1: display = 0x06; break; // One - 1
        case 2: display = 0x5B; break; // Two - 2
        case 3: display = 0x4F; break; // Three - 3
        case 4: display = 0x66; break; // Four - 4
        case 5: display = 0x6D; break; // Five - 5
        case 6: display = 0x7D; break; // Six - 6
        case 7: display = 0x07; break; // Seven - 7
        case 8: display = 0x7F; break; // Eight - 8
        case 9: display = 0x6F; break; // Nine - 9
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
    
    switch (10) {
        case 10: display = 0b00111001; break; // C - Celcius
    }
    
    wait(1);
    
    switch(1) {
        case 1: display = 0b00000000; break;
    }
    
    wait(.1);
}

void pressedsw1last (void) {
    pressed = 1;
}

void pressedsw2last (void) {
    pressed = 2;
}

int main () {
    
    sw1.mode(PullUp);
    sw1.rise(pressedsw1last);
    sw1.fall(NULL);
    sw2.mode(PullDown);
    sw2.rise(NULL);
    sw2.fall(pressedsw2last);
    
    while(1) {
        
        vout = vouttemp*3.3;
        v_sum = 0;
        for (int i=0; i<1000; i++) {
            v_sum = vout + v_sum;
        }
        v_total_sample = v_sum;
        v_avg = v_sum / 1000.0 ;
        
        if (pressed == 1) {
            fahrenheit_convert();
        }
        
        if (pressed == 2) {
            celcius_convert();
        }
    }
}

