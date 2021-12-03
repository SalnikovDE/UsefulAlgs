#include <vector>

class DSU
{
public:
	DSU(uint32_t n) : set_(n), mass_(n, 1), sets_number_(n)
	{
		for (int i = 0; i < n; i++) set_[i] = i;
	}
	uint32_t get_set(uint32_t n) {
		if (set_[n] == n) return n;
		return set_[n] = get_set(set_[n]);
	}
	void union_set(uint32_t first, uint32_t second) {
		int f, s;
		if ((f = get_set(first)) == (s = get_set(second))) return;
		if (mass_[first] >= mass_[second])
		{
			mass_[first] += mass_[second];
			set_[second] = f;
		} else {
			mass_[second] += mass_[first];
			set_[first] = s;
		}
		sets_number_--;
	}
	uint32_t get_sets_number() {
		return sets_number_;
	}
private:
	std::vector<uint32_t> set_;
	std::vector<uint32_t> mass_;
	uint32_t sets_number_;
};
