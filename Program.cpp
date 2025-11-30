import Dew;
import <string>;
import <functional>;
using namespace Dew;
using namespace std;

class MyClass : public Object {
public:
	int x, y;
	String ToString() const {
		return L":)";
	}
} c;

Event<int> MyEvent;

void Foo(int i) {
	Console.WriteLine(i);
}

int main() {
	return 0;
}

void TestEvent() {
	MyEvent += Foo;
	MyEvent += [](int i) {
		if (i == 114514) {
			Console.WriteLine("WTF??");
		} else {
			Console.WriteLine("o...");
		}
		};

	MyEvent.Invoke(114514);

	MyEvent.Invoke(200);
}