#include <iostream>
#include<list>
#include<vector>
template<class TKey, class TValue>
class TPair {
	TKey _key;
	TValue _val;
public:
	TPair() = default;
	TPair(TKey key, TValue val) : _key(key), _val(val){}
	TValue& val() {
		return _val;
	}
	TKey key() {
		return _key;
	}
	bool operator==(const TPair& other) const { return _key == other._key; }
	bool operator==(const TKey& k) const { return _key == k; }
	bool operator !=(const TPair& other) const { return !(_key == other._key); }
	bool operator !=(const TKey& k) const { return !(_key == k); }
};
template<class TKey, class TValue>
class ITable {
public:
	virtual TValue* search(const TKey& val) const = 0;
	virtual void insert(const TKey& key, const TValue& val) = 0;
	virtual void replace(const TKey& key, const TValue& val) = 0;
	virtual void erase(const TKey& key) = 0;
};
template<class TKey, class TValue>
class UnorderedTableVec : public ITable<TKey, TValue> {
	std::vector<TPair<TKey, TValue>> data;
public:
	UnorderedTableVec() = default;
	TValue* search(const TKey& key) const override {
		for (auto elem : data) {
			if (elem == key) {
				return &elem.val();
			}
		}
		return nullptr;
	}
	void insert(const TKey& key, const TValue& val) override {
		for (auto elem : data) {
			if (elem == key) {
				return;
			}
			data.push_back(TPair<TKey, TValue>(key, val));
		}
	}
	void erase(const TKey& key) override {
		int i = 0;
		for (i=0; data[i] != key; i++) {
			data.erase(data.begin()+i);
		}
	}
	void replace(const TKey& key, const TValue& val) override {
		for (auto elem : data) {
			if (elem == key) {
				elem.val() = val;
				return;
			}
		}
	}
	size_t size() {
		return data.size();
	}
};
template<class TKey, class TValue>
class UnorderedTableOnList : public ITable<TKey, TValue> {
	std::list < TPair < TKey, TValue>> data;
public:
	UnorderedTableOnList() = default;

	TValue* search(const TKey& key) const override {
		for (auto const& elem : data) {
			if (elem == key) {
				return &(elem.val());
			}
		}
		return nullptr;
			

	}

	void insert(const TKey& key, const TValue& val) override {
		for (auto const& elem : data) {
			if (elem == key) {
				return;
			}
		}
		data.push_back(TPair<TKey, TValue>(key, val));
	}

	void erase(const TKey& key) override {

	}

	void replase(const TKey& key, const TValue& val) override {

	}
};

