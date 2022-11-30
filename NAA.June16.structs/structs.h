#pragma once

struct Record
{
	int id;
	double amountBorrowed;
	double interest;
};

struct Subscriber
{
	int id;
	char name[16];//holds up to 15 characters, there must be space for the NULL byte
	//this becomes an array of char with each element set to 0
	//a C string is a NULL terminated char array, that can hlod one less char than the size of the array
	//string functions that work with C strings read until the NULL is found
	//NULL is '\0' or 0
};

struct Records
{
	struct Subscriber user;
	double amountBorrowed;
	double interest;
};