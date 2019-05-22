//
//  main.cpp
//  vaja1
//
//  Created by Andrej Avbelj on 07/03/2019.
//  Copyright © 2019 Andrej Avbelj. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

void CountingSort(vector<int> &numbers){


  int min = *min_element(numbers.begin(), numbers.end());

  for(int i = 0; i < numbers.size(); i++){
    numbers[i] = numbers[i]-min;
  }

  int max = *max_element(numbers.begin(), numbers.end());

  vector<int> C(max+1, 0);
  vector<int> B(numbers.size());

  //std::cout << C.size() << '\n';


  for (int i = 0; i < numbers.size(); i++) {
    C[numbers[i]]=C[numbers[i]]+1;
    //std::cout << C[numbers[i]] << "  " << numbers[i] << endl;
  }

  for (int i = 1; i < C.size(); i++) {
    C[i]=C[i]+C[i-1];
    //std::cout << C[i] << "  " << i << endl;
  }

  for (int i = numbers.size()-1; i >= 0; i--) {
    B[C[numbers[i]]-1] = numbers[i];
    //std::cout << B[C[numbers[i]]-1] << " ";
    C[numbers[i]]--;
  }

  for (int i = 0; i < numbers.size(); i++) {
    B[i]+=min;
    numbers[i] = B[i];
    //std::cout << B[i] << " ";
  }

}

void RomanSort(vector<int> &numbers){
  int min = *min_element(numbers.begin(), numbers.end());

  for(int i = 0; i < numbers.size(); i++){
    numbers[i] = numbers[i]-min;
  }

  int max = *max_element(numbers.begin(), numbers.end());

  vector<int> C(max+1, 0);
  int stevec = 0;

  //std::cout << C.size() << '\n';


  for (int i = 0; i < numbers.size(); i++) {
    C[numbers[i]]=C[numbers[i]]+1;
    //std::cout << C[numbers[i]] << "  " << numbers[i] << endl;
  }

  for (int i = 0; i < C.size(); i++) {
    if(C[i] != 0){
      for(int j=0; j<C[i]; j++){
        numbers[stevec] = i+min;
        stevec ++;
      }
    }
  }

}

void compare(vector<int> &v, vector<int> &v2){

  if (v.size() != v2.size()) {
    std::cout <<  "Ni enaka dolzina!";
    return;
  }
  else{
    for (int i = 0; i < v2.size(); i++) {
      if(v[i] != v2[i]){
        std::cout << "Neki se ne ujema -->"<<v[i]<<"  "<<v2[i]<< '\n';
        return;
      }
    }
    std::cout << "Pravilno razvrsceno" << '\n';
  }
}

int main(int argc, char** argv)
{
    char  *file;
    int a = 0;
    int tmp[] = { 10, -20, 30, 2, 3, -2, -3, 3 , 19 };
    vector<int> num;

    file = argv[2];

    std::fstream myfile(file, std::ios_base::in);

    while(myfile >> a){
      num.push_back(a);
    }

    if(strcmp(argv[1],"0") == 0){
      CountingSort(num);
    }
    else if (strcmp(argv[1],"1") == 0) {
      RomanSort(num);
    }
    else{
      std::cout << "Niste podali pravilnih argumentov !" << '\n';
      return 0;
    }

    std::ofstream outFile("out.txt");
    for (const auto &e : num){
      outFile << e << " ";
    }

    //vector<int> out;
    //std::fstream myfile2("out.txt", std::ios_base::in);

    //while(myfile2 >> a){
      //out.push_back(a);
    //}


    //compare(num, out);
    return 0;
}
