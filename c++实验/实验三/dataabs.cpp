template <class T>
class Pair
{
    public:
        Pair();
        Pair(T first_v,T second_v);

        void set_element(int position,T value);
        T get_element(int position);
    private:
        T first;
        T second;
};

#include<iostream>
int main(void)
{
    Pair<int> score;
    Pair<char> seats;
}

template<class T>
Pair<T>::Pair(T first_v,T second_v):first(first_v),second(second_v){};

template<class T>
void Pair<T>::set_element(int position,T value)
{
    if(position == 1)
        first = value;
    if(position == 2)
        second = value;
}

template<class T>
T pair<T>::void get_element(int position)
{
    if(position == 1)
        return first;
    if(position == 2)
        return second;
}