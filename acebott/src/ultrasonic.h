#ifndef _ULTRASONIC_H__
#define _ULTRASONIC_H__

#define Trig_PIN            13
#define Echo_PIN            14                             

class ultrasonic
{   
     public: 
          void Init(); 
          float Ranging(int Trig, int Echo);
     private:
          
};

#endif
