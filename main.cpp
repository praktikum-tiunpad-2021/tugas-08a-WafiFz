/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 */

#include <iostream>

#include "queue.hpp"

using namespace strukdat::priority_queue;

int main()
{
  std::cout << "membuat queue baru [case_1]" << std::endl;
  auto q = new_queue<int>();
  if(sizeof(q) == sizeof(Queue<int>)) std::cout << "1 Berhasil" << std::endl;

  std::cout << "memasukkan data berdasarkan prioritas [case_2]" << std::endl;
  auto q2 = new_queue<int>();
  enqueue(q2, 1, 5);
  if(top(q2) == 1) std::cout << "2 Berhasil" << std::endl;

  enqueue(q2, 2, 3);
  if(top(q2) == 1) std::cout << "3 Berhasil" << std::endl;

  enqueue(q2, 3, 7);
  if(top(q2) == 3) std::cout << "4 Berhasil" << std::endl;

  enqueue(q2, 4, 5);
  if(top(q2) == 3) std::cout << "5 Berhasil" << std::endl;

  enqueue(q2, 5, 1);
  if(top(q2) == 3) std::cout << "6 Berhasil" << std::endl;

  ElementPtr<int> temp2 = q2.head;

  while(temp2 != nullptr){
  	std::cout << "value: "<< temp2->value << " Prioritas: " << temp2->priority << std::endl;
  	temp2 = temp2->next; 
  }

  std::cout << "menghapus data berdasarkan urutan queue [case_3]" << std::endl;
  auto q3 = new_queue<int>();
  enqueue(q3, 1, 5);
  enqueue(q3, 2, 3);
  enqueue(q3, 3, 7);
  enqueue(q3, 4, 5);
  enqueue(q3, 5, 1);

  dequeue(q3);
  if(top(q3) == 1) std::cout << "7 Berhasil" << std::endl;

  dequeue(q3);
  if(top(q3) == 4) std::cout << "8 Berhasil" << std::endl;

  dequeue(q3);
  if(top(q3) == 2) std::cout << "9 Berhasil" << std::endl;

  dequeue(q3);
  if(top(q3) == 5) std::cout << "10 Berhasil" << std::endl;

  ElementPtr<int> temp3 = q3.head;
  if(temp3->next == nullptr){
  	std::cout << "Queue Kosong!" << std::endl;
  }else{
   	while(temp3 != nullptr){
   		std::cout << "value: "<< temp2->value << " Prioritas: " << temp2->priority << std::endl;
   		temp2 = temp2->next; 
   	}
  }
  return 0;
}
