#include "libs/Starter/src/Starter.cpp"

int main(int argc, char* argv[]) {
	run::Starter<int> starter;
	starter.execute(argc, argv);

	for (auto res : starter.get_result()) {
		std::cout << res << '\n';
	}

	return 0;
}
