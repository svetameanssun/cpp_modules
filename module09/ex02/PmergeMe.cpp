// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)
//Jacobsthal sequence is limits, not indexes
#include <iostream>
#include <vector>

std::vector<int> jacobsthalSeq(int pendSize){
    std::vector<int> jcbSec;
    std::vector<int> resArr(pendSize); 

    if (pendSize == 0 || pendSize == 1){
        return (resArr); 
    }

    jcbSec.push_back(0);
    jcbSec.push_back(1);

    resArr[0] = 1;

    if (pendSize == 2){
        return (resArr);
    }

    int a = 2;
    while(a <= pendSize){
        int res = jcbSec[a - 1] + 2 * jcbSec[a - 2];
        if (res <= pendSize){
            jcbSec.push_back(res);
        }
        else{
            break;
        }
        a++;
    }

    jcbSec.erase(jcbSec.begin(), jcbSec.begin() + 2);

    std::cout << "Jacobsthal sequence:\n";
    for (size_t i = 0; i < jcbSec.size(); ++i) {
        std::cout << "[" << jcbSec[i] << "], ";
    }
    std::cout << std::endl;

    int i = 0;
    int j = 1;
    int high;
    int low;

    // --- основные блоки ---
    while(i < (int)jcbSec.size() - 1){
        high = jcbSec[i + 1];
        low = jcbSec[i];

        while(high > low){
            resArr[j] = high;
            high--;
            j++;
        }
        i++;
    }

    // --- ВАЖНО: последний блок (остаток) ---
    if (!jcbSec.empty()){
        high = pendSize - 1;
        low = jcbSec.back();

        while(high > low){
            resArr[j] = high;
            high--;
            j++;
        }
    }

    return (resArr);
}

int main(){
    std::vector<int> indexes = jacobsthalSeq(20);

    std::cout << "index sequence:\n";
    //Ноль впереди подразумевается
    for (size_t i = 0; i < indexes.size() - 1; ++i) {
        std::cout << "[" << indexes[i] << "], ";
    }
    std::cout << std::endl;
}
/*#include <iostream>
#include <vector>

  std::vector<int> jacobsthalSeq(int pendSize){
    std::vector<int> jcbSec;
    std::vector<int> resArr(pendSize); 
    if (pendSize == 0 || pendSize == 1){
       return (resArr); 
    }
    jcbSec.push_back(0);
    jcbSec.push_back(1);
    resArr[0] = 1;
    if (pendSize == 2){
      return (resArr);
    }
    int a = 2;
    while(a <= pendSize){
      int res = jcbSec[a - 1] + 2 * jcbSec[a - 2];
      if (res <= pendSize){
        jcbSec.push_back(res); // to make sure the limits do not excede pending chain size.
      }
      else{
        break;
      }
      a++;
    }
    jcbSec.erase(jcbSec.begin(), jcbSec.begin() + 2);// removed 0 and a repeited 1, o sea, first two elements.
    std::cout << "Jacobsthal sequence: \n: ";
      for (int i = 0; i < jcbSec.size(); ++i) {
      std::cout << "[" << jcbSec[i] << "], ";
    }
    std::cout << std::endl;
    int i = 0;
    int j = 1;
    int high;
    int low;
    
    while(i < jcbSec.size() - 1){
      if (jcbSec[i + 1]){
        high = jcbSec[i + 1];
        low = jcbSec[i];
      }
      else {
        high = pendSize - 1;
        low = jcbSec[i];
      }
      std::cout << "high: " <<high << std::endl;
      std::cout << "low: " << low << std::endl;
      while(high > low){
        resArr[j] = high;
        high--;
        j++;
      }
      i++;
    }
    return (resArr);
}

int main(){
  std::vector <char> vect(12);
  std::cout << "pending chain: "
  for (int i = 0; i < 12; ++i) {
    vect[i] = 'a' + (i % 26);
    std:cout << "[" < v[i] < "], ";
  }
  std::cout << std::endl;

  std::vector <int> indexes = jacobsthalSeq(30);
  std::cout << "index sequence to use to insert pending chain\n: ";
  for (int i = 0; i < indexes.size(); ++i) {
    std::cout << "[" << indexes[i] << "], ";
  }
  std::cout << std::endl;
}*/



/**
template <typedef T>
void fordJohnson(T &seq){
  T & mainChain;
  T & pendChain;
  bool even = 1;
  size_t seqSize = seq.size();
  if (seqSize == 1){
      return;
  }
  if (seqSize%2 != 0){
    seqSize--;
    even = 0;
  }
  for(int i = 0; i < seqSize - 1; i+=2){
    if (seq.at(i) == seq.at(i + 1){
      throw (Exception &repeated);
    }
    else if (seq.at(i) < seq.at(i + 1)){
      pendChain.push_back(seq.at(i));
      mainChain.push_back(seq.at(i + 1));
    }
    else if (seq.at(i) > seq.at(i + 1)){
      pendChain.push_back(seat index 1: " << v[1] <<
  if (!even){
    pendChain.push_back(seq.at(seqSize));
  }
  
  if (seqSize >= 2){
    fordJohnson(mainChain);
  }
  
}*/




