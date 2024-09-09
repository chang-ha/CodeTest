#include <iostream>
#include <TimeCheck\TimeCheck.h>

#include<vector>
using namespace std;

// 너비 우선 탐색
// 같은 너비 우선해서 탐색
#include <queue>
int BFSsolution(vector<vector<int> > maps)
{
	int answer = 0;

	std::vector<std::vector<bool>> VisitMaps;

	const size_t Col_maps_size = maps.size();
	VisitMaps.resize(Col_maps_size);
	for (size_t i = 0; i < Col_maps_size; i++)
	{
		const size_t Row_maps_size = maps[i].size();
		VisitMaps[i].resize(Row_maps_size);

		for (size_t j = 0; j < Row_maps_size; j++)
		{
			VisitMaps[i][j] = maps[i][j];
		}
	}

	return answer;
}

// 깊이 우선 탐색
// 노드의 가장 깊은 노드까지 들어가서 탐색
int DFSsolution(vector<vector<int> > maps)
{
	int answer = 0;
	return answer;
}

int main()
{
	BFSsolution({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1}});
	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
		});

	TIME_UNIT ETime = CheckFunctionTime([&]()
		{
		});

	std::cout << "ATime is " << ATime.count() << " microseconds" << std::endl;
	std::cout << "BTime is " << BTime.count() << " microseconds" << std::endl;
	std::cout << "CTime is " << CTime.count() << " microseconds" << std::endl;
	std::cout << "DTime is " << DTime.count() << " microseconds" << std::endl;
	std::cout << "ETime is " << ETime.count() << " microseconds" << std::endl;
	int x = 0;
}