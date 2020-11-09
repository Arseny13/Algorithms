#include <stdlib.h>
class myset {
    public:
        myset(size_t using T=unsigned char size=256){
            body = new T[(size+7)/8];
            this->size = size;
            for(size_t i=0;i<(size+7)/8;i++){
                }body[i]=0;
        }
        ~myset(){
            delete [] body;
        }
        bool insert(size_t elem){
            if (elem>=size) return false;
            body[elem >>3] |= (1<<(elem&7)); // >> 3 это делить на 8  |= или равно  &7 это как процент %8 останток от делеение
            return true;
        }
        bool erase(size_t elem){
            //&=~() //доделать
            if (elem>=size) return false;
            body[elem >>3] &= ~(1<<(elem&7));
            return true;
        }
        //   in    (body[elem>>3]>>(elem%8))&1
    private:
        T *body;
        size_t size;

    };
