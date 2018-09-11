// A Hello World! program in c#
/* hello world */
using System;
using System.Diagnostics;
using System.Reflection;

// can contain zro
namespace HelloWorld
{
    class PropertyClass {
        private string codeMessage;
        public string code {
            get {
                return codeMessage;
            }
            set {
                codeMessage = value;
            }
        }
    }

    struct YourStruct {

    }

    interface IYourInterface {

    }

    class Hello
    {
        // optional int
        // optional args(String[])
        [Conditional("DEBUG")]
        public void foo() {}

        static void Main()
        {
            Type type = typeof(Hello);
            foreach (MethodInfo m in type.GetMethods()) {
                foreach (Attribute attribute in m.GetCustomAttributes(false)) {
                    ConditionalAttribute cattribute = (ConditionalAttribute)attribute;
                    if (cattribute != null) {
                        Console.WriteLine(cattribute);
                    }
                }
            }
        }
    }
}
