#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void incryption(string& phrase);
void decryption(string& phrase);
static void noKey(string& phrase, string& incrypted);
void decritionWithOutKey(string& phrase);
int chiave();