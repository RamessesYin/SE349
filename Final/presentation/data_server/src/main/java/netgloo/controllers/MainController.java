package netgloo.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


import org.apache.log4j.Logger;

@Controller
public class MainController {
	private Logger logger = Logger.getLogger(getClass());
  @RequestMapping("/")
  @ResponseBody
  public String index() {
	  
    return "Welcome to my server";
	 // return Time.getTime();
  }
  
  

}
