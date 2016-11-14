#include <syslog.h>

void process(){
  syslog(LOG_NOTICE, "Writing to my syslog");
}

int main(int argc, char *argv[]){
  setlogmask( LOG_UPTO(LOG_NOTICE) );
  openlog("dummyd", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

  process();

  closelog();
  return(1);
}
