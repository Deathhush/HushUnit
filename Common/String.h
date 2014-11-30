// ****************************************************************************
// Hush
//
// AUTHOR:  Justin Shen
//
// NOTES: 
//     A immutable string class
//     Copy on reference and the string buffer is managed using reference counting
//
// ****************************************************************************

#ifndef HUSH_STRING_H
#define HUSH_STRING_H

#include "BasicType.h"
#include <memory>

using namespace std;

class StringTests;

namespace Hush
{
	class String
	{
		friend StringTests;

	private:
		class StringData
		{
		public:
			StringData(const Char* source, Bool isExternalData)
			{
				this->length = wcslen(source);
				this->isExternalData = isExternalData;

				// Copy the string if we own the data
				// Otherwise just point to the original data
				if (!this->isExternalData)
				{
					this->data = new Char[this->length + 1];
					memcpy(this->data, source, this->length*sizeof(Char));
					this->data[this->length] = L'\0';
				}
				else
				{
					this->data = const_cast<Char*>(source);
				}
			}

			~StringData()
			{
				// Only delete the data if we own it
				if (!this->isExternalData)
				{
					delete[] data;
				}				
			}

			Char* data;
			Bool isExternalData;
			Int32 length;
		};

	private:
		String()
		{
		}

		shared_ptr<StringData> data;

	public:
		String(const Char* source, bool isExternalData = false)
			: data(new StringData(source, isExternalData))
		{			
		}

		String(String& sourceString)
			:data(sourceString.data)
		{
		}

		String& operator=(const String& sourceString)
		{
			data = sourceString.data;
			return *this;
		}

		const Char* GetValue()
		{
			return (*data).data;
		}	

	public:
		static String WrapToString(const Char* source)
		{
			return String(source, true);
		}

		static String Empty;
	};
}

#endif