// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)
//Jacobsthal sequence is limits, not indexes
  int *jacobsthalSeq(int pendSize){
    std::vect<int> jcblSec;
    if (pendSize == 0){
       return NULL; 
    }
    jcblSec[0] = 0; 
    if (pendSize == 1){
      return ;
    }
    jcbsthlSec[1] = 1; 
    if (pendSize == 2){
      return;
    }
    int i = 2;
    while(i < pendSize){
      int res = jcblSec[i - 1] + 2 * jcblSec[i - 2];
      if (res <= pendSize){
        jcblSec[i] = res; // to make sure the limits do not excede pending chain size.
      }
      else{
        break;
      }
      i++;
    }
    jcblSec.erase(0, 2);// removed 0 and a repeited 1, o sea, first two elements.
    int resArr[pendSize];
    resArr[0] = 1;
    int highLimit = jcblSec[2];
    int lowLimit = jcblSec[1];
    int jcslIndex = 3;
    int index = 1;
    //I have to refactor this, it is unclear and propably erroneo
    /*while(highLimit >= lowLimit && jcblSec[jcslIndex]){
      if (highLimit == lowLimit){
        {
          if (!jcblSec[jcslIndex + 1]){
              int temp = pendSize - 1;
              resArr[index] = temp--;
          }
          else
          highLimit = jcblSec[jcblIndex + 1]
          lowLimit = jcblSec[jcblIndex];
          jcblIndex++;
        }
      }
      else}
        resArr[index] = highLimit;
        highlimit--;
    }
    }*/
    return (resArr);
}


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
      pendChain.push_back(seq.at(i + 1));
      mainChain.push_back(seq.at(i));
    }
  }
  if (!even){
    pendChain.push_back(seq.at(seqSize));
  }
  
  if (seqSize >= 2){
    fordJohnson(mainChain);
  }
  
}




