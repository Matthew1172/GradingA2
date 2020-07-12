#include "sequence2.h"
using namespace assignment_sequence2;

sequence::sequence() {
	this->head_ptr = NULL;
	this->tail_ptr = NULL;
	this->current_ptr = NULL;
	this->many_nodes = list_length(this->head_ptr);
}

sequence::sequence(const sequence& source) {
	
}

sequence::~sequence() {
	list_clear(this->head_ptr);
	delete this->head_ptr;
	delete this->current_ptr;
	delete this->tail_ptr;
	this->many_nodes = 0;
}

void sequence::start() {
	this->current_ptr = this->head_ptr;
}

void sequence::end() {
	this->current_ptr = this->tail_ptr;
}

void sequence::advance() {
	this->current_ptr = this->current_ptr->link();
	//try { if (is_item()) this->current_index++; }
	//catch (const std::exception & e) { exit(1); }
}

void sequence::insert(const sequence::value_type& entry) {
	if (!is_item()) {
		list_head_insert(this->head_ptr, entry);
		this->many_nodes++;
		this->current_ptr = this->head_ptr++;
		this->tail_ptr = this->current_ptr;
	}
	else {
		list_insert(this->current_ptr--, entry);
		this->many_nodes++;
		this->current_ptr = this->current_ptr++;
	}
}

void sequence::attach(const value_type& entry) {
	if (this->many_nodes < 1) {
		list_head_insert(this->head_ptr, entry);
		this->current_ptr = this->head_ptr;
		this->tail_ptr = this->current_ptr;
	}
	else {
		if (!is_item()) this->current_ptr = this->tail_ptr-1;

		if (this->tail_ptr - 1 == this->current_ptr) {
			node* insert = new node(entry);
			this->tail_ptr->set_link(insert);
			this->tail_ptr = insert;
			this->current_ptr = this->tail_ptr;
		}
		else {
			list_insert(this->current_ptr--, entry);
		}
	}
	this->many_nodes++;
}

void sequence::remove_current() {
	if (this->tail_ptr != this->current_ptr) {
		node* t = this->current_ptr++;
		list_remove(this->current_ptr--);
		this->current_ptr = t;
	}
	else {
		this->tail_ptr = this->current_ptr--;
		this->current_ptr--->set_link(NULL);
		delete this->current_ptr;
		this->current_ptr = NULL;
	}
}

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

}
