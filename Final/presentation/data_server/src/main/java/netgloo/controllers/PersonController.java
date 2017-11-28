package netgloo.controllers;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


import netgloo.models.AtPerson;
import netgloo.models.AtPersonDao;
import netgloo.models.PrePerson;
import netgloo.models.PrePersonDao;
import netgloo.models.Tag;
import netgloo.models.TagDao;

/**
 * A class to test interactions with the MySQL database using the OrderDao class.
 *
 * @author netgloo
 */
@Controller
public class PersonController {

  // ------------------------
  // PUBLIC METHODS
  // ------------------------
 
  @RequestMapping("/getPreInfoByName")
  @ResponseBody
  public  Iterable<PrePerson> getPre(String name,HttpServletRequest request,HttpServletResponse response) {
	  HttpSession session=request.getSession();
	  response.setHeader("Access-Control-Allow-Origin", "*");
		//if(session.getAttribute("name")==null)return -1;
		//long userId=Long.parseLong(session.getAttribute("id").toString());
	  Iterable<PrePerson> PrePerson = null;

    try {

    	PrePerson =PrePersonDao.findByName(name);
   
    }
    catch (Exception ex) {
      return null;
    }
    return PrePerson;
  }
  
  
  @RequestMapping("/getAtInfoByName")
  @ResponseBody
  public  Iterable<AtPerson> getPreInfo(String name,HttpServletRequest request,HttpServletResponse response) {
	  HttpSession session=request.getSession();
	  response.setHeader("Access-Control-Allow-Origin", "*");
		//if(session.getAttribute("name")==null)return -1;
		//long userId=Long.parseLong(session.getAttribute("id").toString());
	  Iterable<AtPerson> AtPerson = null;

    try {

    	AtPerson =AtPersonDao.findByName(name);
   
    }
    catch (Exception ex) {
      return null;
    }
    return AtPerson;
  }
  
  
  @RequestMapping("/getTagByName")
  @ResponseBody
  public  Tag getTag(String name,HttpServletRequest request,HttpServletResponse response) {
	  HttpSession session=request.getSession();
	  response.setHeader("Access-Control-Allow-Origin", "*");
		//if(session.getAttribute("name")==null)return -1;
		//long userId=Long.parseLong(session.getAttribute("id").toString());
	  Tag Tag = null;

    try {

    	Tag =TagDao.findByName(name);
   
    }
    catch (Exception ex) {
      return null;
    }
    return Tag;
  }
  
  
  
  

  
  

  

  // ------------------------
  // PRIVATE FIELDS
  // ------------------------
  @Autowired
  private PrePersonDao PrePersonDao;

  @Autowired
  private TagDao TagDao;
  @Autowired
  private AtPersonDao AtPersonDao;
  
} // class OrderController

