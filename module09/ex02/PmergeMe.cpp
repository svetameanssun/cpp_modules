// Jacobsthal Sequence
//J(n) = J(n-1) + 2 * J(n-2)


  void jacobSeq(std::vector<int> & seq, int pendSize){
    if (pendSize == 0){
       return ; 
    }
    seq.push_back(0); 
    if (pendSize == 1){
      return ;
    }
    seq.push_back(1); 
    if (pendSize == 2){
      return;
    }
    int i = 2;
    while(i < pendSize){
      seq.push_back(seq.at(i - 1) + 2 * seq.at(i - 2));
      i++;
    }
}
