// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)
//Jacobsthal sequence is limits, not indexes
#include <iostream>
#include <vector>
#include <algorithm>


typedef struct PairStruct {
    int big;
    int small;
} PairS;


int binarySearchBounded(std::vector <int>& arr, int value, int bound) {
    int left = 0;
    int right = bound;
    while(left < right) {
        int mid = (left + right) / 2;
        if(arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

std::vector<int> jacobsthalSeq(size_t pendSize) {
    std::vector<int> jcbSec;
    std::vector<int> resArr(pendSize);

    if(pendSize == 0) {
        return resArr;
    }
    resArr[0] = 0;
    if(pendSize == 1) {
        return resArr;
    }
    jcbSec.push_back(0);
    jcbSec.push_back(1);
    resArr[0] = 1;


    if(pendSize == 2) {
        return (resArr);
    }

    int a = 2;
    while(a <= pendSize) {
        int res = jcbSec[a - 1] + 2 * jcbSec[a - 2];
        if(res <= pendSize) {
            jcbSec.push_back(res);
        } else {
            break;
        }
        a++;
    }
    //удаляем первые 2  элемента
    jcbSec.erase(jcbSec.begin(), jcbSec.begin() + 2);

    std::cout << "Jacobsthal sequence:\n";
    for(size_t i = 0; i < jcbSec.size(); ++i) {
        std::cout << "[" << jcbSec[i] << "], ";
    }
    std::cout << std::endl;

    int i = 0;
    int j = 1;
    int high;
    int low;

    // --- основные блоки ---
        std::cout << "First while:" << "\n";
    
    while(i < (int)jcbSec.size() - 1) {
        high = jcbSec[i + 1];
        std::cout << "high = " << high << "\n";

        low = jcbSec[i];
        std::cout << "low = " << high << "\n";

        while(high > low) {
            resArr[j] = high;
            std::cout << "resArr[j] = " << resArr[j] << "\n";
            high--;
            j++;
        }
        i++;
    }

    // --- ВАЖНО: последний блок (остаток) ---
    if(!jcbSec.empty()) {
        high = pendSize - 1;
        std::cout << "high = pendSize - 1;" << high <<'\n';
        low = jcbSec.back();

        while(high > low) {
            resArr[j] = high;
            high--;
            j++;
        }
    }

    std::cout << std::endl;
    std::cout << "Insertion order:\n";
    for(size_t i = 0; i < resArr.size(); ++i) {
        std::cout << "[" << resArr[i] << "], ";
    }
    std::cout << std::endl;
    return (resArr);
}


template <typename T>
void fordJohnson(T &seq) {
    std::vector <PairS> pairChain;
    std::vector<int> mainChain;
    int straggler;
    bool hasStraggler = false;
    // T mainChain;
    //T pendChain;
    size_t seqSize = seq.size();
    /*if(seqSize == 0) {
        return;
    }
    if(seqSize == 1) {
        mainChain.push_back(seq[0]);
        return;
    }*/
    if(seqSize <= 1) {
        //mainChain.push_back(seq[0]);
        return;
    }
    if(seqSize % 2 != 0) {
        //Added this condition
        /*if (seqSize == 1){
            hasStraggler = false;
        }*/
        straggler = seq.at(seqSize - 1);
        hasStraggler = true;
    }
    for(size_t i = 0; i < seqSize - 1; i += 2) {
        if(seq.at(i) == seq.at(i + 1)) {
            return ;
            //throw  myException("duplicate values");
        }
        if(seq.at(i) < seq.at(i + 1)) {
            pairChain.push_back({seq.at(i + 1), seq.at(i)});
        } else if(seq.at(i) > seq.at(i + 1)) {
            pairChain.push_back({seq.at(i), seq.at(i + 1)});
        }
    }

    //Added this condition
    //if (!pairChain.empty()){
    for(size_t i = 0; i < pairChain.size(); i++)
        mainChain.push_back(pairChain[i].big);
    //}

    //Added this condition
    //if (seqSize > 1 )  {
    fordJohnson(mainChain);
    //}
    /*else{
        mainChain.push_back(seq[0]);
    }*/
    std::vector<int> insrtSec = jacobsthalSeq(pairChain.size());
    std::cout << "pairChain size: " << pairChain.size() << "\n";


    // --- STEP 5: insert pending (small) ---
    // there is SOMETHING WRONG with this insertion,
    // I lack 1st and last element of the array!
    mainChain.insert(mainChain.begin(), pairChain[0].small);
    std::cout << "pairChain[4].big = " << pairChain[4].small << "\n";
    
    for(size_t k = 0; k < insrtSec.size() - 1; k++) {
        int index = insrtSec[k];

        if(index >= (int)pairChain.size())
            continue;
        std::cout << "pairChain[" << index << "].small = " << pairChain[index].small << "\n";
        int value = pairChain[index].small;
        std::cout << "pairChain[" << index << "].big = " << pairChain[index].big << "\n";
        int boundValue = pairChain[index].big;
        /*if(index == 0) {
            mainChain.insert(mainChain.begin(), value);
            continue;
        }*/

        int boundInd = std::find(mainChain.begin(), mainChain.end(), boundValue)
                       - mainChain.begin();

        int pos = binarySearchBounded(mainChain, value, boundInd);

        mainChain.insert(mainChain.begin() + pos, value);
    }

    // --- STEP 6: insert straggler ---
    if(hasStraggler) {
        int pos = binarySearchBounded(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
    }
    // --- STEP 7: copy back result ---
    seq.clear();
    for(size_t i = 0; i < mainChain.size(); i++)
        seq.push_back(mainChain[i]);

}



int main() {

    std::vector<int> vec = {'a', 115, 119, 98, 99, 'z', 113, 110, 104, 102};
    fordJohnson(vec);

    std::cout << "result:\n";
    for(size_t i = 0; i < vec.size(); ++i) {
        std::cout << "[" << vec[i] << "], ";
    }
    std::cout << std::endl;

}




