// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)
//Jacobsthal sequence is limits, not indexes
#include <iostream>
#include <vector>


typedef struct PairStruct{
    int big;
    int small;
} PairS;


template <typedef T>
int binarySearchBounded(T<int>& arr, int value, int bound){
    int left = 0;
    int right = arr.size();
    while(left < right){
        int mid = (left + right)/ 2;
        if (value >  arr[mid]){
            left = mid + 1;
        }
        else{
            right = mid;
            if (value < bound){
                right = bound;
            }
        }
    }
    return left;
}

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

template <typedef T>
void fordJohnson(T <int>&seq){
    T <PairS> pairChain;
    int straggler;
    bool hasStraggler = false;
    
    
// T mainChain;
  //T pendChain;
  size_t seqSize = seq.size();
  if (seqSize == 1){
      return ;
  }
  if (seqSize%2 != 0){
      seqSize--;
      straggler = seq.at(seqSize);
      hasStraggler = true;
  }
  for(int i = 0; i < seqSize - 1; i+=2){
    if (seq.at(i) == seq.at(i + 1){
        throw (Exception &repeated);
    }
    else if (seq.at(i) < seq.at(i + 1)){
        pairChain[i].small = seq.at(i);
        pairChain[i].big = seq.at(i + 1);
        //pendChain.push_back(seq.at(i));
        //mainChain.push_back(seq.at(i + 1));
    }
    else if (seq.at(i) > seq.at(i + 1)){
        pairChain[i].small = seq.at(i + 1);
        pairChain[i].big = seq.at(i);
        //pendChain.push_back(seq.at(i + 1));
        //mainChain.push_back(seq.at(i));
  }
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairChain.size(); i++)
        mainChain.push_back(pairs[i].big);

    if (seqSize >= 2){
        fordJohnson(mainChain);
  }
      std::vector<int> jcbSec = jacobsthalSeq(int pairChain.size());
      for(int index : jcbSec){
          int value = pairChain[index].small;
          int boundValue = pairChain[index].big;

          int boundInd std::find(mainChain.begin(), mainChain.end(), boundValue) - mainChain.begin();
          int pos = binarySearchBounded(mainChain, value, boundInd);
            mainChain.insert(naibChain.begin() + pos, value);
          }
  
}

}




