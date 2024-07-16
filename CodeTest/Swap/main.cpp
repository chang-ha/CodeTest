#include "../TimeCheck/TimeCheck.h"

void SwapInt(int& a, int& b)
{
	std::swap(a, b);
}

void TempSwapInt(int &a, int &b)
{
	// std::swap���� ����ϰų� ����
	int Temp = a;
	a = b;
	b = Temp;
}

// https://stackoverflow.com/questions/70922392/performance-of-stdvectorswap-vs-stdvectoroperator
#include <vector>
void SwapVector(std::vector<int>& _Left, std::vector<int>& _Right)
{
	std::swap(_Left, _Right);

	// ���ʰ� ������ �ּҸ� �ٲ��ְ�
	// void _Swap_adl(_Ty& _Left, _Ty& _Right) noexcept(_Is_nothrow_swappable<_Ty>::value) {
	//	swap(_Left, _Right);
	
	// ���ʰ� �������� ���� �ٲ���
	// _Mypair._Myval2._Swap_val(_Right._Mypair._Myval2);
}

void TempSwapVector(std::vector<int>& _Left, std::vector<int>& _Right)
{
	// std::swap���� �ξ� ����
	// vector�� Ŀ������ ���̴� ������
	// operator = �� ������ �����ϸ鼭 �纻�� ����� ������ ����
	std::vector<int>& TempVector = _Left;
	_Left = _Right; 
	// ���ο��� Left vector�� deAlloc�ϰ� first, last, end = nullptr;
	// ===========���� �ڵ�==========
	// auto& _Al       = _Getal();
	// auto& _Right_al = _Right._Getal();
	// if constexpr (_Choose_pocca_v<_Alty>) {
	// 	if (_Al != _Right_al) {
	// 		_Tidy();
	// 		_Mypair._Myval2._Reload_proxy(_GET_PROXY_ALLOCATOR(_Alty, _Al), _GET_PROXY_ALLOCATOR(_Alty, _Right_al));
	// 	}
	// }
	// 
	// _Pocca(_Al, _Right_al);
	// auto& _Right_data = _Right._Mypair._Myval2;
	// _Assign_counted_range(_Right_data._Myfirst, static_cast<size_type>(_Right_data._Mylast - _Right_data._Myfirst));


	// 
	// _My_data._Orphan_all(); // free all storage
	// 
	// if (_Myfirst) { // destroy and deallocate old array
	// 	_Destroy_range(_Myfirst, _Mylast, _Al);
	// 	_ASAN_VECTOR_REMOVE;
	// 	_Al.deallocate(_Myfirst, static_cast<size_type>(_Myend - _Myfirst));
	// 
	// 	_Myfirst = nullptr;
	// 	_Mylast = nullptr;
	// 	_Myend = nullptr;
	// }

	// Right Vector�� ������
	// Left Vector�� �Ű��ִ� ����
	//	auto& _Al = _Getal();
	//	auto& _My_data = _Mypair._Myval2;
	//	pointer& _Myfirst = _My_data._Myfirst;
	//	pointer& _Mylast = _My_data._Mylast;
	//	pointer& _Myend = _My_data._Myend;
	//
	//	constexpr bool _Nothrow_construct = conjunction_v<is_nothrow_constructible<_Ty, _Iter_ref_t<_Iter>>,
	//		_Uses_default_construct<_Alloc, _Ty*, _Iter_ref_t<_Iter>>>;
	//
	//	_My_data._Orphan_all();
	//	const auto _Oldcapacity = static_cast<size_type>(_Myend - _Myfirst);
	//	if (_Newsize > _Oldcapacity) {
	//		_Clear_and_reserve_geometric(_Newsize);
	//		if constexpr (_Nothrow_construct) {
	//			_Mylast = _Uninitialized_copy_n(_STD move(_First), _Newsize, _Myfirst, _Al);
	//			_ASAN_VECTOR_CREATE;
	//		}
	//		else {
	//			_ASAN_VECTOR_CREATE_GUARD;
	//			_Mylast = _Uninitialized_copy_n(_STD move(_First), _Newsize, _Myfirst, _Al);
	//		}
	//		return;
	//	}
	//
	//	const auto _Oldsize = static_cast<size_type>(_Mylast - _Myfirst);
	//	if (_Newsize > _Oldsize) {
	//		bool _Copied = false;
	//		if constexpr (_Iter_copy_cat<_Iter, pointer>::_Bitcopy_assignable) {
	//#if _HAS_CXX20
	//			if (!_STD is_constant_evaluated())
	//#endif // _HAS_CXX20
	//			{
	//				_Copy_memmove_n(_First, static_cast<size_t>(_Oldsize), _Myfirst);
	//				_First += _Oldsize;
	//				_Copied = true;
	//			}
	//		}
	//
	//		if (!_Copied) {
	//			for (auto _Mid = _Myfirst; _Mid != _Mylast; ++_Mid, (void) ++_First) {
	//				*_Mid = *_First;
	//			}
	//		}
	//
	//		if constexpr (_Nothrow_construct) {
	//			_ASAN_VECTOR_MODIFY(static_cast<difference_type>(_Newsize - _Oldsize));
	//			_Mylast = _Uninitialized_copy_n(_STD move(_First), _Newsize - _Oldsize, _Mylast, _Al);
	//		}
	//		else {
	//			_ASAN_VECTOR_EXTEND_GUARD(_Newsize);
	//			_Mylast = _Uninitialized_copy_n(_STD move(_First), _Newsize - _Oldsize, _Mylast, _Al);
	//			_ASAN_VECTOR_RELEASE_GUARD;
	//		}
	//	}
	//	else {
	//		const pointer _Newlast = _Myfirst + _Newsize;
	//		_Copy_n_unchecked4(_STD move(_First), _Newsize, _Myfirst);
	//		_Destroy_range(_Newlast, _Mylast, _Al);
	//		_ASAN_VECTOR_MODIFY(static_cast<difference_type>(_Newsize - _Oldsize));
	//		_Mylast = _Newlast;
	//	}

	// ���� �Ȱ��� ���� �� ��
	_Right = TempVector;
}

void MoveVector(std::vector<int>& _Left, std::vector<int>& _Right)
{
	// ���Ͱ� ������ operator = ���� ��������
	// ���Ͱ� Ŀ���� std::move�� �� ����
	// ������ std::swap���� �� ����
	std::vector<int> TempVector = std::move(_Left);
	_Left = std::move(_Right);

	// Left Vector�� deAlloc�ϰ�
	// Right Vector�� ���� ���ҵ��� Left Vector�� �ű� (first, last, end ���...)
	// _Alty& _Al = _Getal();
	// _Alty& _Right_al = _Right._Getal();
	// constexpr auto _Pocma_val = _Choose_pocma_v<_Alty>;
	// if constexpr (_Pocma_val == _Pocma_values::_No_propagate_allocators) {
	// 	if (_Al != _Right_al) {
	// 		_Move_assign_unequal_alloc(_Right);
	// 		return *this;
	// 	}
	// }
	_Right = std::move(TempVector);
}

#include <numeric>
#define SMALL_VECTOR_SIZE 100
#define LARGE_VECTOR_SIZE 100000
int main()
{
	int a = INT_MAX;
	int b = INT_MIN;	

	std::vector<int> SmallLeftVector(SMALL_VECTOR_SIZE);
	std::vector<int> SmallRightVector(SMALL_VECTOR_SIZE);
	std::iota(SmallLeftVector.begin(), SmallLeftVector.end(), 0);
	std::iota(SmallRightVector.begin(), SmallRightVector.end(), 100);

	std::vector<int> LargeLeftVector(LARGE_VECTOR_SIZE);
	std::vector<int> LargeRightVector(LARGE_VECTOR_SIZE);
	std::iota(LargeLeftVector.begin(), LargeLeftVector.end(), 0);
	std::iota(LargeRightVector.begin(), LargeRightVector.end(), 0);

	TIME_UNIT ATime = CheckFunctionTime([&]()
		{
			SwapInt(a , b);
		});

	TIME_UNIT BTime = CheckFunctionTime([&]()
		{
			TempSwapInt(a, b);
		});

	TIME_UNIT CTime = CheckFunctionTime([&]()
		{
			SwapVector(SmallLeftVector, SmallRightVector);
		});

	TIME_UNIT DTime = CheckFunctionTime([&]()
		{
			TempSwapVector(SmallLeftVector, SmallRightVector);
		});

	TIME_UNIT DTime2 = CheckFunctionTime([&]()
		{
			MoveVector(SmallLeftVector, SmallRightVector);
		});

	TIME_UNIT FTime = CheckFunctionTime([&]()
		{
			SwapVector(LargeLeftVector, LargeRightVector);
		});

	TIME_UNIT GTime = CheckFunctionTime([&]()
		{
			TempSwapVector(LargeLeftVector, LargeRightVector);
		});

	TIME_UNIT GTime2 = CheckFunctionTime([&]()
		{
			MoveVector(LargeLeftVector, LargeRightVector);
		});
	return 0;
}