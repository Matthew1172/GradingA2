#include "sequence2.h"
using namespace assignment_sequence2;

sequence::sequence() {
	this->head_ptr = NULL;
	this->tail_ptr = NULL;
	this->current_ptr = NULL;
	this->pre = NULL;
	this->many_nodes = 0;
}

sequence::sequence(const sequence& source) {
	if (source.current_ptr == NULL) {
		list_copy(source.head_ptr, this->head_ptr, this->tail_ptr);
		this->current_ptr = NULL;
		this->pre = NULL;
	}
	else if (source.current_ptr == source.head_ptr) {
		list_copy(source.head_ptr, this->head_ptr, this->tail_ptr);
		this->pre = NULL;
		this->current_ptr = this->head_ptr;
	}
	else {
		list_piece(source.head_ptr, source.pre, this->head_ptr, this->pre);
		list_piece(source.current_ptr, source.tail_ptr, this->current_ptr, this->tail_ptr);
		this->pre->set_link(this->current_ptr);
	}
	this->many_nodes = source.many_nodes;
}

sequence::~sequence() {
	list_clear(this->head_ptr);
	this->many_nodes = 0;
}

void sequence::start() {
	this->current_ptr = this->head_ptr;
	this->pre = NULL;
}

void sequence::end() {
	this->current_ptr = this->tail_ptr;
}

void sequence::advance() {
	this->pre = this->current_ptr;
	this->current_ptr = this->current_ptr->link();
}

void sequence::insert(const sequence::value_type& entry) {
	if (this->many_nodes < 1) {
		list_head_insert(this->head_ptr, entry);
		this->pre = this->head_ptr;
		this->current_ptr = this->head_ptr;
		this->tail_ptr = this->head_ptr;
	}
	else if (!is_item() || this->current_ptr == this->head_ptr) {
		list_head_insert(this->head_ptr, entry);
		this->pre = this->head_ptr;
		this->current_ptr = this->head_ptr;
		//this->tail_ptr = this->head_ptr;
	}
	else {
		list_insert(this->pre, entry);
		this->current_ptr = this->pre->link();
		//this->current_ptr = this->current_ptr->link();
	}
	this->many_nodes++;
}

void sequence::attach(const value_type & entry) {
	/* If empty, set tail */
	if (many_nodes < 1) {
		list_head_insert(this->head_ptr, entry);
		this->pre = this->head_ptr;
		this->current_ptr = this->head_ptr;
		this->tail_ptr = this->head_ptr;
	}
	/* If no item or cursor points to the last item, insert at tail */
	else if (!is_item() || this->current_ptr == this->tail_ptr) {
		this->pre = this->tail_ptr;
		list_insert(this->tail_ptr, entry);
		this->tail_ptr = this->tail_ptr->link(); /* Update tail */
		this->current_ptr = this->tail_ptr;
	}
	/* Attaches at the middle of the list */
	else {
		this->pre = this->current_ptr;
		list_insert(this->current_ptr, entry);
		this->current_ptr = this->current_ptr->link();
	}
	this->many_nodes++;
}

void sequence::remove_current() {
	if (this->many_nodes <= 1) {
		list_head_remove(this->head_ptr);
		this->current_ptr = NULL;
		this->pre = NULL;
	}
	else if (this->current_ptr == this->head_ptr) {
		this->current_ptr = this->head_ptr->link();
		list_head_remove(this->head_ptr);
	}
	else if (this->current_ptr == this->tail_ptr) {
		list_remove(this->pre);
		this->pre = NULL;
		this->current_ptr = NULL;
	}
	else {
		this->current_ptr = this->current_ptr->link();
		list_remove(this->pre);
	}
	this->many_nodes--;
}
/*
void sequence::remove_current() {
	if (this->tail_ptr != this->current_ptr) {
		node* t = this->current_ptr+1;
		list_remove(this->current_ptr-1);
		this->current_ptr = t;
	}
	else {
		this->tail_ptr = this->current_ptr--;
		this->current_ptr--->set_link(NULL);
		delete this->current_ptr;
		this->current_ptr = NULL;
	}
}
*/


size_t sequence::size() const {
	return this->many_nodes;
}

bool sequence::is_item() const {
	if (this->current_ptr != NULL) return true;
	else return false;
}

sequence::value_type sequence::current() const {
	return this->current_ptr->data();
}

void assignment_sequence2::sequence::operator=(const sequence& source)
{
	if (this == &source) return;
	list_clear(this->head_ptr);
	this->many_nodes = 0;
	list_copy(source.head_ptr, this->head_ptr, this->tail_ptr);
	this->many_nodes = source.many_nodes;
}
