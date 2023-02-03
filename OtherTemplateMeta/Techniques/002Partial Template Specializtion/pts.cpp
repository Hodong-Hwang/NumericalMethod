class ModalDialog;
class MyController;
class Window;
class Controller;

class Button;

template <class Window, class Controller>
class Widget
{
    //... generic implementation ...
};

// ... specialized implementation ...
template <>
class Widget<ModalDialog, MyController>
{
};

// ModalDialog and MyController are classes defined by your application.

// // Partial specialization of Widget
template <class Window>
class Widget<Window, MyController>
{
};

//. further partially specialize Widgets for all Button instantiations and MyController
template <class ButtonArg>
class Widget<Button<ButtonArg>, MyController>
{
};

template <class T, class U>
T Fun(U obj); // primary template
template <class U>
void Fun<void, U>(U obj); // illegal partial specialization
template <class T>
T Fun(Window obj); // legal (overloading)

// Local Class
local classes cannot define static member variables and cannot access nonstatic local variables.void Fun()
{
    class Local
    {
        ... member variables...... member function definitions...
    };
    ... code using Local...
}
// MakeAdapter implements an interface on the fly with the help of a local class.

class Interface
{
public:
    virtual void Fun() = 0;
    24 ...
};
template <class T, class P>
Interface *MakeAdapter(const T &obj, const P &arg)
{
    class Local : public Interface
    {
    public:
        Local(const T &obj, const P &arg)
            : obj_(obj), arg_(arg) {}
        virtual void Fun()
        {
            obj_.Call(arg_);
        }

    private:
        T obj_;
        P arg_;
    };
    return new Local(obj, arg);
}
