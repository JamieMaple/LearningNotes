using System;
using System.Threading.Tasks;


namespace Program {
    class Test {
        public static void Main(string[] args) {
            runAsyncTask();
            runSyncTask();
        }
        
        public static async void runAsyncTask() {
            await Task.Run(() => { 
                    for (int i = 0; i < 100; i++) {
                        Console.WriteLine("run in async task:", i);
                    }
            });
        }

        public static void runSyncTask() {
            for (int i = 0; i < 25; i++) {
                Console.WriteLine("run in sync task: ", i);
            }
        }
    }
}
