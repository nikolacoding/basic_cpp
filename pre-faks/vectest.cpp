#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 15

vector<int> get_nums(int n);
void shell_sort(vector<int>& vec);

int main(void)
{
    int n;
    
    do{
        cout << "n = ";
        cin >> n;
    } while (n < 1 || n > MAX);

    vector<int> nums = get_nums(n);
    shell_sort(nums);
    cout << "Brojevi u vektoru: ";
    for (int num : nums)
        cout << num << " ";

    return 0;
}

vector<int> get_nums(int n){
    vector<int> ret_vec;
    for (int i = 0; i < n; i++){
        int num;
        cout << "[" << i + 1 << "] " << "Unesi broj: ";
        cin >> num;
        ret_vec.push_back(num);
    }
    return ret_vec;
}

void shell_sort(vector<int>& vec){
    int i, j, h, temp;

    for (h = (int)vec.size() / 2; h > 0; h /= 2){
        for (i = 1; i < (int)vec.size(); i++){
            temp = vec[i];
            for (j = i; j >= h && vec[j - h] > temp; j -= h)
                vec[j] = vec[j - h];
            vec[j] = temp;
        }
    }
}