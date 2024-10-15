#include <string>
#include <vector>

// ¹®Á¦
// https://school.programmers.co.kr/learn/courses/30/lessons/172927

using namespace std;

#include <stdexcept>
#include <algorithm>
#include <numeric>
int solution(vector<int> picks, vector<string> minerals)
{
	// ±¤¹° °¹¼ö
	const int minerals_size = static_cast<int>(minerals.size());
	if (0 == minerals_size)
	{
		return 0;
	}

	// °î±ªÀÌ °¹¼ö
	const int picks_count = std::accumulate(picks.begin(), picks.end(), 0);
	if (0 == picks_count)
	{
		return 0;
	}

	// °î±ªÀÌ °¹¼ö¸¦ ³ÑÀ» ¼ö ¾øÀ½
	const int minerals_vector_size = std::min(minerals_size / 5 + 1, picks_count);
	// Sum minerals Value , Sum minerals count
	std::vector<std::pair<int, int>> minerals_vector(minerals_vector_size, { 0, 0 });

	for (int i = 0, j = 0; i < minerals_size && j < picks_count; i++, j = i / 5)
	{
		int minerals_value = 0;
		
		if ("diamond" == minerals[i])
		{
			minerals_value = 25;
		}
		else if ("iron" == minerals[i])
		{
			minerals_value = 5;
		}
		else if ("stone" == minerals[i])
		{
			minerals_value = 1;
		}
		else
		{
			throw std::invalid_argument("argument contains not mineral's name");
		}

		// ±¤¹°º° Value¸¦ ´õÇÔ
		minerals_vector[i / 5].first += minerals_value;
		// ±¤¹°ÀÇ °¹¼ö¸¦ ´õÇÔ
		minerals_vector[i / 5].second += 1;
	}

	// ±¤¹° Value·Î Sort
	std::sort(minerals_vector.begin(), minerals_vector.end(), [](const std::pair<int, int>& First, const std::pair<int, int>& Second)
		{
			return First.first > Second.first;
		});

	int answer = 0;

	for (int i = 0, Cur_pick = 0; i < minerals_vector_size; i++)
	{
		while (0 == picks[Cur_pick])
		{
			++Cur_pick;
		}

		switch (Cur_pick)
		{
		// ´ÙÀÌ¾Æ °î±ªÀÌ
		case 0:
			// ÇÇ·Îµµ = ±¤¹°ÀÇ °¹¼ö
			answer += minerals_vector[i].second;
			break;
		// Ã¶ °î±ªÀÌ
		case 1:
		{
			// Value°¡ 5ÀÇ ¹è¼ö°¡ ³ª¿À´Â °æ¿ì
			// 1. Ã¶ 5°³ or µ¹ 5°³
			// 2. ´ÙÀÌ¾Æ 1°³
			// 3. ´ÙÀÌ¾Æ·Î¸¸ ÀÌ·ç¾î Áü
			if (5 == minerals_vector[i].first)
			{
				// 5 iron or 5 ston or 1 dia
				// ÇÇ·Îµµ = ±¤¹°ÀÇ °¹¼ö
				answer += minerals_vector[i].second;
			}
			else
			{
				// ÇÇ·Îµµ = value / 5 + value % 5 (´ÙÀÌ¾Æ Ä³´Âµ¥ ÇÇ·Îµµ 5 ¼Ò¸ð + ³ª¸ÓÁö ±¤¹° Ä³´Âµ¥ ÇÇ·Îµµ 1 ¼Ò¸ð)
				answer += minerals_vector[i].first / 5 + minerals_vector[i].first % 5;
			}
			break;
		}
		// µ¹ °î±ªÀÌ
		case 2:
			// ÇÇ·Îµµ = ±¤¹°ÀÇ Value
			answer += minerals_vector[i].first;
			break;
		default:
			throw std::invalid_argument("pick type invalid");
		}

		picks[Cur_pick] -= 1;
	}

	return answer;
}