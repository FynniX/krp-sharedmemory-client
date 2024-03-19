import Wrapper from "./lib/wrapper";
import pidusage from "pidusage";

const wrapper = new Wrapper();
wrapper.on("connected", () => console.log("connected"));
wrapper.on("disconnected", () => console.log("disconnected"));
wrapper.activate();

setInterval(() => {
  pidusage(process.pid, (err, stats) => {
    if (err) throw err;
    console.log(stats);
  });
}, 2000);
