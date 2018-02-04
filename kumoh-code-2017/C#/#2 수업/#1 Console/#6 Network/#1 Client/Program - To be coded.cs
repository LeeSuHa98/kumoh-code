using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
To be coded
 */
using System.IO;

namespace EchoClient
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] data = new byte[1024];
            string input, stringData;
            // To be coded (Hint: Declare TcpClient Variable - 변수명: server)

            try
            {
                // To be coded (Hint: Connect to Server)
            }
            catch (SocketException)
            {
                Console.WriteLine("Unable to connect to server");
                return;
            }

            // Read Hello Message
            // To be coded (Hint: Make NetworkStream from server - 변수명: ns)
            int recv = ns.Read(data, 0, data.Length);
            Console.WriteLine(Encoding.ASCII.GetString(data, 0, recv));

            while (true)
            {
                // Type Message for sending
                input = Console.ReadLine();
                if ("exit" == input)
                    break;

                // Send Message to Server
                // To be coded (Hint: Encoding.ASCII.GetBytes(input))                               

                recv = ns.Read(data, 0, data.Length);
                Console.WriteLine("> Echo: " + Encoding.ASCII.GetString(data, 0, recv));
            }

            Console.WriteLine("Disconnecting from server ...");
            // To be coded (Hint: Close Network Stream)
            // To be coded (Hint: Close TCP Connection)
        }
    }
}
