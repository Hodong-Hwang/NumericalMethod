// 자료형 확장을 위함.
template <typename Base>
class MixtureClass : Base
{
    //Mixin 기법은 임의의 슈퍼클래스를 감싸는 구조가 된다.
    // 슈퍼클래스를 직접 호출할 수 없기 때문에 Proxy 클래스로볼 수 있다.
    // MeshObject는 Mixin 상속으로 구현되어 있으며
    // MeshObjectType은CRTP 구조로 되어 있음.

    // MeshObjectType
    //   |
    // MeshObject <>--- Mesh
};

// CRTP

template <typename Derived>
class CRTP
{

};

// 내클래스가 무엇인지 알려주기 위함.

class Derived : public CRTP<Derived>
{

};