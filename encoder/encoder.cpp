// encoder.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string encryption(string plaintext, string key)
{
	string encrypted;
	int n = key.length();
	int textlength = plaintext.length();
	double temp = static_cast<double>(textlength) / n;
	int modulo = textlength % n;
	int m = ceil(temp);
	int t = m - 1;
	char* tab = NULL;
	tab = new char[n];
	char** tablica = new char*[m];
	for (int i = 0; i < m; i++)
		tablica[i] = new char[n];
	//wpisywanie tekstu do tablicy
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != t)
			{
				tablica[i][j] = plaintext[i*n + j];

			}

			else if (i == t && modulo == 0)
			{

				{
					tablica[i][j] = plaintext[i*n + j];
				}

			}
			else if (i == t && j < modulo)
			{

				{
					tablica[i][j] = plaintext[i*n + j];
				}

			}
			else
			{
				tablica[i][j] = 'x';
			}

		}
	}
	//wpisywanie klucza do tablicy
	for (int i = 0; i < n; i++)
	{
		int min = key[0];
		int index = 0;
		for (int j = 0; j < n; j++)
		{
			if (min > key[j])
			{
				min = key[j];
				index = j;
			}
		}
		tab[i] = index;
		key[index] = 125;
	}
	int k;
	//wpisywanie zaszyfrowanego tekstu do stringa
	for (int i = 0; i < n; i++)
	{
		k = tab[i];
		for (int j = 0; j < m; j++)
		{
			if (k >= 0)
			{
				encrypted += tablica[j][k];
				k--;
			}
			else
			{
				k = n - 1;
				encrypted += tablica[j][k];
				k--;
			}
		}
	}

	return encrypted;
}

int main()
{
	string plaintext, encrypted, decrypted, key;
	key = "maroko";
	ofstream encoded_file, decoded_file;
	ifstream plaintext_file;
	string line;
	plaintext_file.open("plain.txt");
	if (plaintext_file.is_open())
	{
		while (getline(plaintext_file, line))
		{
			plaintext += line;
		}
		plaintext_file.close();
	}
	else cout << "Unable to open file";
	encrypted = encryption(plaintext, key);
	encoded_file.open("encoded.txt");
	encoded_file << encrypted;
	encoded_file.close();
}