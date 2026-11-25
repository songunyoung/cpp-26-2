#include<iostream>

int sumScores(const int scores[], int count) {
    int total= 0;
    for(int i= 0; i< count-1; ++i) {
    total += scores[i];
    }
    return total;
}

int main() {
    const int scores[] = {10, 20, 30};
    int result= sumScores(scores, 3);
    std::cout<< result<< '\n';
}