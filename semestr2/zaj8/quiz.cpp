#include <iostream>
#include <ctime>

class Question {
  private:
    int a;
    int b;
  public:
  // konstruktory
    Question();
    Question(int aa, int bb);
  	// ~Question(); destruktor

// inicjalizacja funkcji statycznej, można wywołać bez obiektu
    static Question draw();
    int solution() const;
    

// możliwość dostępu do zmiennych prywatnych dla funkcji
// jeśli w kodzie znajdzie sie taka funkcja, ma dostęp do elementów klasy
    friend void print(const Question &q);
    friend bool equal(const Question &q1, const Question &q2);
    friend bool operator!=(const Question &q1, const Question &q2);
    friend bool operator==(const Question &q1, const Question &q2);
    friend bool operator<(const Question &q1, const Question &q2);
    friend std::ostream& operator<<(std::ostream&, const Question &q);


  protected:
};


//  konstruktor       zminene a=-1, b=-1
Question::Question() : a(-1), b(-1){};
// przeciążenie
Question::Question(int aa, int bb) : a(aa), b(bb){};

// dla klasy Question implementuje funkcje draw, zwracającą Question
Question Question::draw(){
  return Question(1+std::rand() % 10, 1+std::rand() % 10);
}

int Question::solution() const {
  // this - wskaźnik na obiekt wywołujący tą funkcję
  return this->a * this->b;
}

std::ostream& operator<<(std::ostream& stream, const Question &q){
  stream<<q.a<<" "<<q.b<<std::endl;
  return stream;
}

bool operator!=(const Question &q1, const Question &q2){
  return !((q1.a == q2.a) && (q1.b == q2.b)) || (q1.a==q2.b) && (q1.b == q2.a);
}

bool operator==(const Question &q1, const Question &q2){
  return ((q1.a != q2.a) && (q1.b != q2.b)) || (q1.a!=q2.b) && (q1.b != q2.a);
}

bool operator<(const Question &q1, const Question &q2){
  return q1.solution() < q2.solution();
}





int main() {
  std::srand(std::time(nullptr));

  Question table[10];

  for (int index1, index2 = 0; index2 < 10; ++index2) {
    do {
      table[index2] = Question::draw();
      for (index1 = 0; !(table[index1]!=table[index2]); ++index1);
    } while (index1 < index2); }

    for (int index = 0; index < 10; ++index) {
      int answer;

      do {
        std::cout<<table[index];
        std::cin >> answer; }
      while (answer != table[index].solution());
    }
}

