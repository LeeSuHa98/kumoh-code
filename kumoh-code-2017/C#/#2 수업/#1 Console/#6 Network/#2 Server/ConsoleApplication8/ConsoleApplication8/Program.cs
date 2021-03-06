﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;

using System.Net;
using System.Net.Sockets;
using System.IO;

namespace EchoServer
{
    class Program
    {
        static void Main(string[] args)
        {
            int recv;
            byte[] data = new byte[1024];

            // To be coded (Hint: Make TcpListener Socket - 변수명 newSock)
            TcpListener newSock = new TcpListener(IPAddress.Any, 1111);
            // To be coded (Hint: Start Listener Socket)
            newSock.Start();

            Console.WriteLine("Waiting for a client ... ");
            // To be coded (Hint: Wait for TCP Connection from TcpClient - 변수명 client)
            TcpClient client = newSock.AcceptTcpClient();

            Console.WriteLine("Connected: " + client.Client.RemoteEndPoint);

            // To be coded (Hint: Make NetworkStream from TCP Client Stream - 변수명 ns)
            NetworkStream ns = client.GetStream();

            string welcome = " Welcome to C# Echo Server.";
            data = Encoding.ASCII.GetBytes(welcome);
            ns.Write(data, 0, data.Length);

            while (true)
            {
                try
                {
                    recv = ns.Read(data, 0, data.Length);
                }
                catch
                {
                    break;
                }

                if (recv == 0)
                    break;

                Console.WriteLine(client.Client.RemoteEndPoint + " " + Encoding.ASCII.GetString(data, 0, recv));
                ns.Write(data, 0, recv);
            }

            // To be coded (HInt: Close NetworkStream)
            // To be coded (Hint: Close TCP Connection from TcpClient)
            // To be coded (Hint: Close TcpListener Socket)
            ns.Close();
            client.Close();
            newSock.Stop();
        }
    }
}
