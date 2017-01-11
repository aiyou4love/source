#include "../../Serialize.hpp"

namespace cc {
	
	int8_t stringAccount(const string& nValue)
	{
		size_t length_ = nValue.length();
		if ( (length_ < 5) || (length_ > 20) ) {
			return 2;
		}
		if ( !isalpha(nValue[0]) ) {
			return 3;
		}
		for ( size_t i = 0; i < nValue.length(); ++i ) {
			if ( (!isalnum(nValue[i])) 
				&& ('_' == nValue[i]) ) {
				return 4;
			}
		}
		return 1;
	}
	
	int8_t stringPassword(const string& nValue)
	{
		size_t length_ = nValue.length();
		if ( (length_ < 6) || (length_ > 20) ) {
			return 2;
		}
		int aln_ = 0;
		int nal_ = 0;
		for ( size_t i = 0; i < nValue.length(); ++i ) {
			if ( (!isalnum(nValue[i])) 
				&& ('_' == nValue[i]) ) {
				aln_++;
			} else {
				nal_++;
			}
		}
		if ( (aln_ <= 0) || (nal_ <= 0) ) {
			return 3;
		}
		return 1;
	}
	
	string stringDelete(const string& nValue, char nDel)
	{
		string value_("");
		for (size_t i = 0; i < nValue.length(); ++i) {
			if (nValue[i] == nDel) {
				continue;
			}
			value_.push_back(nValue[i]);
		}
		return value_;
	}
	
	string stringTrim(const string& nValue, const string& nTrim)
	{
		string value_("");
		for (size_t i = 0; i < nValue.length(); ++i) {
			if ((nValue[i] == ' ') || (nValue[i] == '\t')
				|| (nValue[i] == '\r') || (nValue[i] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( nValue[i] == nTrim[j] ) {
					continue_ = true;
					break;
				}
			}
			if (continue_) {
				continue;
			}
			value_ = nValue.substr(i);
			break;
		}
		for (size_t i = value_.length(); i > 0; --i) {
			if ((value_[i - 1] == ' ') || (value_[i - 1] == '\t')
				|| (value_[i - 1] == '\r') || (value_[i - 1] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( value_[i - 1] == nTrim[j] ) {
					continue_ = true;
					break;
				}
			}
			if (continue_) continue;
			value_ = value_.substr(0, i);
			break;
		}
		return value_;
	}
	
	string stringTrimLeft(const string& nValue, const string& nTrim)
	{
		string value_("");
		for (size_t i = 0; i < nValue.length(); ++i) {
			if ((nValue[i] == ' ') || (nValue[i] == '\t')
				|| (nValue[i] == '\r') || (nValue[i] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( nValue[i] == nTrim[j] ) {
					continue_ = true;
					break;
				}
			}
			if (continue_) {
				continue;
			}
			value_ = nValue.substr(i);
			break;
		}
		return value_;
	}
	
	string stringTrimRight(const string& nValue, const string& nTrim)
	{
		string value_("");
		for (size_t i = value_.length(); i > 0; --i) {
			if ((value_[i - 1] == ' ') || (value_[i - 1] == '\t')
				|| (value_[i - 1] == '\r') || (value_[i - 1] == '\n')) {
				continue;
			}
			bool continue_ = false;
			for (size_t j = 0; j < nTrim.length(); ++j) {
				if ( value_[i - 1] == nTrim[j] ) {
					continue_ = true;
					break;
				}
			}
			if (continue_) continue;
			value_ = value_.substr(0, i);
			break;
		}
		return value_;
	}
	
	string stringBackslant(const string& nValue)
	{
		string result_ = stringTrim(nValue, "/\\");
		for (size_t i = 0; i < result_.length(); ++i) {
			if ( result_[i] == '\\' ) {
				result_[i] = '/';
			}
		}
		return result_;
	}
	
}
