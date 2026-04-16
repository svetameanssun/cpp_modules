// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)


  void jacobSeq(std::vector<int> & seq, int seqSize){
    if (seqSize == 0){
       return ; 
    }
    seq.push_back(0); 
    if (seqSize == 1){
      return ;
    }
    seq.push_back(1); 
    if (seqSize == 2){
      return;
    }
    int i = 2;
    while(i < seqSize){
      seq.at(i) = seq.at(i - 1) + 2 * seq.at(i - 2);
      i++;
    }
}
