#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T value;
  T priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> qNew = new Element<T>;
  qNew->value = value;
  qNew->priority = priority;
  qNew->next = nullptr;
  if(q.head == nullptr && q.tail == nullptr){
  	q.head = qNew;
  	q.tail = qNew;
  }else{
  	ElementPtr<T> qHelp = q.head;
  	while (qNew->priority < qHelp->priority){
  		if (qHelp->next == nullptr) break;
  		qHelp = qHelp->next;
  	}

  	if(qHelp == q.head && qNew->priority > qHelp->priority){
  		qNew->next = qHelp;
  		q.head = qNew;
  	}else if(qHelp == q.tail && qNew->priority <= qHelp->priority){
  		qHelp->next = qNew;
  		q.tail = qNew;
  	}else {
  		qNew->next = qHelp->next;
  		qHelp->next = qNew;
  	}
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->value;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
	ElementPtr<T> qDel = q.head;
	q.head = q.head->next;
	qDel->next = nullptr;
	delete qDel;
}

}  // namespace priority_queue

}  // namespace strukdat
