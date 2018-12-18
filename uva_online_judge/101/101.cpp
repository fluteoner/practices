#include <iostream>
#include <list>
#include <string>

void init_blocks(std::list<int> *&blocks, int *&block_at, int size)
{
	blocks = new std::list<int> [size];
	block_at = new int[size];

	for (int i = 0; i < size; i++) {
		blocks[i].push_back(i);
		block_at[i] = i;
	}
}

void print_block(const std::list<int> block)
{
	for (auto v : block) {
		std::cout << " " << v;
	}
	std::cout << std::endl;
}

void print_blocks(const std::list<int> *blocks, const int size)
{
	for (int i = 0; i < size; i++) {
		std::cout << i << ":";
		print_block(blocks[i]);
	}
}

void move_a_to_b(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	int block = blocks[block_at[src_block]].back();
	blocks[block_at[src_block]].pop_back();
	blocks[block_at[dst_block]].push_back(block);
	block_at[block] = block_at[dst_block];
}

void move_pile_to_block(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	int src_block_index = block_at[src_block];
	int dst_block_index = block_at[dst_block];

	auto it = blocks[src_block_index].begin();

	while (*it != src_block) {
		++it;
	}

	auto it_cut = it;

	while (it != blocks[src_block_index].end()) {
		block_at[*it] = dst_block_index;
		++it;
	}

	blocks[dst_block_index].splice(blocks[dst_block_index].end(), blocks[src_block_index], it_cut, blocks[src_block_index].end());
}

void restore_one_block(std::list<int> *blocks, int *block_at, int src_block_index)
{
	int dst_block_index = blocks[src_block_index].back();

	/* Return the top block to its origin position */
	blocks[src_block_index].pop_back();
	blocks[dst_block_index].push_back(dst_block_index);

	/* Update new position in the table */
	block_at[dst_block_index] = dst_block_index;
}

void restore_block_until(std::list<int> *blocks, int *block_at, int until_block)
{
	int block_index = block_at[until_block];

	while (blocks[block_index].back() != until_block) {

		restore_one_block(blocks, block_at, block_index);
	}
}

void move_onto(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	//std::cout << "move_onto " << src_block << " " << dst_block << std::endl;
	restore_block_until(blocks, block_at, src_block);
	restore_block_until(blocks, block_at, dst_block);
	move_a_to_b(blocks, block_at, src_block, dst_block);
}
void move_over(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	//std::cout << "move_over " << src_block << " " << dst_block << std::endl;
	restore_block_until(blocks, block_at, src_block);
	move_a_to_b(blocks, block_at, block_at[src_block], block_at[dst_block]);
}
void pile_onto(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	//std::cout << "pile_onto " << src_block << " " << dst_block << std::endl;
	restore_block_until(blocks, block_at, dst_block);
	move_pile_to_block(blocks, block_at, src_block, dst_block);
}
void pile_over(std::list<int> *blocks, int *block_at, int src_block, int dst_block)
{
	//std::cout << "pile_over " << src_block << " " << dst_block << std::endl;
	move_pile_to_block(blocks, block_at, src_block, dst_block);
}

void exec_cmd(std::string main_cmd, int *block_at, std::string sub_cmd, int src_block, int dst_block, std::list<int> *blocks) {

	if (main_cmd == "move") {

		if (sub_cmd == "onto") {
			move_onto(blocks, block_at, src_block, dst_block);
		} else if (sub_cmd == "over") {
			move_over(blocks, block_at, src_block, dst_block);
		}
	} else if (main_cmd == "pile") {

		if (sub_cmd == "onto") {
			pile_onto(blocks, block_at, src_block, dst_block);
		} else if (sub_cmd == "over") {
			pile_over(blocks, block_at, src_block, dst_block);
		}
	}
}

int unit_test(void)
{
	std::list<int> *blocks;
	int *block_at;
	int size = 7;

	init_blocks(blocks, block_at, size);

	move_a_to_b(blocks, block_at, 2, 3);
	print_blocks(blocks, size);

	move_onto(blocks, block_at, 1, 2);
	print_blocks(blocks, size);

	//move_over(blocks, block_at, 0, 7);
	//print_blocks(blocks, size);

	//pile_onto(blocks, block_at, 7, 2);
	//print_blocks(blocks, size);

	//pile_over(blocks, block_at, 7, 2);
	//print_blocks(blocks, size);
}

int main()
{
	std::list<int> *blocks;
	int *block_at;
	int size;
	std::string main_cmd, sub_cmd;
	int src_block, dst_block;

	/* Unit Test */
	//unit_test();

	std::cin >> size;

	init_blocks(blocks, block_at, size);

	while (std::cin >> main_cmd) {

		if (main_cmd == "quit") break;

		std::cin >> src_block >> sub_cmd >> dst_block;
		//print_blocks(blocks, size);
		if (block_at[src_block] == block_at[dst_block]) continue;
		exec_cmd(main_cmd, block_at, sub_cmd, src_block, dst_block, blocks);
	}

	print_blocks(blocks, size);

	return 0;
}
