#include <iostream>
#include <string.h>
using namespace std;

#define IN_ZONE(x) ((x + 256) % 256 >= ZONE_START || (x + 256) % 256 <= ZONE_END)

// параметры запрещенной зоны
const int ZONE_START = 243;
const int ZONE_END = 31;
const int ZONE_LEN = 45;


int prompt_string(u_char ** msg); // возвращает длину строки
void encrypt(u_char * msg, int msg_n, u_char * key, int key_n);
void decrypt(u_char * msg, int msg_n, u_char * key, int key_n);


int main () 
{
    u_char * msg; // сообщение
    int msg_n; // длина сообщения
    u_char * key; // ключ
    int key_n;  // длина ключа

    cout << "Введите сообщение для зашифровки:\n";
    msg_n = prompt_string(&msg);

    cout << "Введите ключ шифрования:\n";
    key_n = prompt_string(&key);



    encrypt(msg, msg_n, key, key_n);
    
    cout << "Зашифрованная строка:\n" << msg << endl;
    
    decrypt(msg, msg_n, key, key_n);

    cout << "Расшифрованная строка:\n" << msg << endl;



    return 0;
}


void encrypt(u_char * msg, int msg_n, u_char * key, int key_n)
{
    int key_tmp, 
        sign; // в какую сторону смещение

    for (int i = 0, key_i = 0; i < msg_n; i++, key_i = (key_i + 1) % key_n)
    {
        if (!IN_ZONE(msg[i]))
        {
            key_tmp = key[key_i] % ZONE_LEN;

            sign = 2*(key[key_i] % 2) - 1; // -1 если четное, +1 если нечетное

            msg[i] += sign * key_tmp;
            if (IN_ZONE(msg[i]))
                msg[i] += sign * ZONE_LEN;
        }
    }
}


void decrypt(u_char * msg, int msg_n, u_char * key, int key_n)
{
    int key_tmp,
        sign; // в какую сторону смещение

    for (int i = 0, key_i = 0; i < msg_n; i++, key_i = (key_i + 1) % key_n)
    {
        if (!IN_ZONE(msg[i]))
        {
            sign = 2*(key[key_i] % 2) - 1; // -1 если четное, +1 если нечетное
            
            key_tmp = key[key_i] % ZONE_LEN;

            msg[i] -= sign * key_tmp;
            if (IN_ZONE(msg[i]))
                msg[i] -= sign * ZONE_LEN;
            
        }
    }
}


int prompt_string(u_char ** msg)
{
    string temp;
    getline(cin, temp);

    *msg = new u_char [temp.length()];
    memcpy(*msg, temp.c_str(), temp.length());

    return temp.length();    
}
