#include <vector>
#include <functional> 
#include <stdio.h>
#include "word.h"

int main()
{
    base();


    
    scanf("%s", sen);

    while (sen[num] != NULL)
    {
        len++;
        num++;
    }

    s_range = Range[(int)sen[0] - first_Ac];
    printf("%d\n", s_range.first);

    for (int i = s_range.first - 1; i <= s_range.last - 1; i++)
        if (word[i].len == len)
            _word.push_back(word[i]);
                  
        
    first = 0;
    last = _word.size() -  1;
    for (int i = first; i <= last; i++)
        printf("%s\n", _word[i].sen);

    mid = (first + last) / 2;

    printf("%d\n", _word.size());

    while (true)
    {
        if (sen[len - 1] == _word[mid].sen[len - 1])
            break;
        mid = (first + last) / 2;

        if ((int)sen[1 + ad] < (int)_word[mid].sen[1 + ad])
            last = mid;
        else if ((int)sen[1 + ad] > (int)_word[mid].sen[1 + ad])
            first = mid;
        else if ((int)sen[1 + ad] == (int)_word[mid].sen[1 + ad])
        {
            l_num = mid + 2;
            f_num = mid - 2;

            while(true)
            {
                if ((int)sen[2 + ad] == (int)_word[mid].sen[2 + ad])
                {
                    l_num = l_num + 2;
                    continue;
                }

                l_num = mid - 1;
                if ((int)sen[2 + ad] == (int)_word[mid].sen[2 + ad])
                    last = l_num;
                else
                    last = l_num - 1;
                break;
            }

            while (true)
            {
                if ((int)sen[2 + ad] == (int)_word[mid].sen[2 + ad])
                {
                    f_num = f_num + 2;
                    continue;
                }
                    
                f_num = mid + 1;
                if ((int)sen[2 + ad] == (int)_word[mid].sen[2 + ad])
                    first = f_num;
                else
                    first = f_num + 1;
                break;
            }
        }
        ad++;
    }

    printf("%s", _word[mid].sen);

    



    
    
    

    //printf("%d", len);

    
            
   
    return 0;
}
      

