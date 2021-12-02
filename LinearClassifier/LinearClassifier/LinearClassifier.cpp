// LinearClassifier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "data.h"
using namespace std;

int main()
{
    int img;

    cout << "Enter Image data set to classify: ";
    cin >> img;

    typedef float(*weights)[28];
    typedef unsigned char (*images)[28];
    

    images Img_Data[10] = {
        Image1, Image2,
        Image3, Image4,
        Image5, Image6,
        Image7, Image8,
        Image9, Image10  
    };

    weights Addrress[10] = {
        weight_data_0, weight_data_1,
        weight_data_2, weight_data_3,
        weight_data_4, weight_data_5,
        weight_data_6, weight_data_7,
        weight_data_8, weight_data_9
    };

    float largest_sum = 0;
    int largest_lbl = 0;

    for (int weight = 0; weight < 10; weight++)
    {
        float sum[28][28] = {};
        float score = 0;

        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                sum[i][j] = Img_Data[img-1][i][j] * Addrress[weight][i][j];
            }
        }

        for (int i = 0; i < 28; i++)
        {
            for (int j = 0; j < 28; j++)
            {
                score += sum[i][j];
            }
        }

        if (score > largest_sum)
        {
            largest_sum = score;
            largest_lbl = weight;
        }
    }

    int classify = Labels[img-1];

    string guess;

    if (classify == largest_lbl)
    {
        guess = "Correct classification";
    }
    else
    {
        guess = "Incorrect classification";
    }

    cout << "Linear classifier output: " << largest_lbl << "\nwith a score of: " << largest_sum;
    cout << "\nThe label for this  image is: " << classify;
    cout << "\n" << guess;
    cout << endl;


}
