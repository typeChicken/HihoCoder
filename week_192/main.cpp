#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    std::cout << "Hello, World!" << std::endl;
    string input_string;
    cin >> input_string;
    int character_aggregate[26] = {0};
    char output_matrix[5][5];
    int already_output_character_num = 0;
    int offset = (int) 'A';
    character_aggregate['J'-offset]=1;
    for (int i = 0; i < input_string.size(); ++i)
    {
        char item = input_string.at(i);
        if(item == 'J')
            item = 'I';
        if(character_aggregate[item-offset] == 0)
        {
            output_matrix[already_output_character_num/5][already_output_character_num%5] = item;
            character_aggregate[item-offset]=1;
            ++already_output_character_num;
        }


    }
    for(char i = 'A';i<='Z';++i)
    {
        if(character_aggregate[i-offset]==0)
        {
            output_matrix[(already_output_character_num)/5][(already_output_character_num)%5]=i;
            character_aggregate[i-offset]=1;
            ++already_output_character_num;
        }
    }
    for(int i=0;i<25;++i)
    {
        if(i%5==0 && i!=0)
            cout<<endl;
        cout<<output_matrix[i/5][i%5];

    }


    return 0;
}